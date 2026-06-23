#ifndef FORM_HPP
# define FORM_HPP
#include "Bureaucrat.hpp"

class Form {
    private :
        const std::string _name;
        bool _isSigned;
        const int _gradeTosign;
        const int _gradeToexecute;
        
    public :
        Form();
        ~Form();
        Form(const std::string name, int gradeTosign, int gradeToexecute);
        Form(const Form &src);
        Form & operator=(const Form &src);
        const std::string &getName() const;
        bool getIsSigned() const;
        const int &getGradeTosign() const;
        const int &getGradeToexecute() const;
        void    beSigned(const Bureaucrat &bureaucrat);
        class GradeTooHighException : public std::exception {
            public :
                virtual const char* what() const throw() {
                    return "Grade is too high!";
                };
        };
        class GradeTooLowException : public std::exception {
            public :
                virtual const char * what() const throw() {
                    return "Grade is too low!";
                };
        };
};
std::ostream & operator<<(std::ostream &e, const Form &src);

#endif