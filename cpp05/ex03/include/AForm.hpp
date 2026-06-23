#ifndef AFORM_HPP
# define AFORM_HPP
#include "Bureaucrat.hpp"

class AForm {
    private :
        const std::string _name;
        bool _isSigned;
        const int _gradeTosign;
        const int _gradeToexecute;
        
    public :
        AForm();
        virtual ~AForm();
        AForm(const std::string name, int gradeTosign, int gradeToexecute);
        AForm(const AForm &src);
        AForm & operator=(const AForm &src);
        const std::string &getName() const;
        bool getIsSigned() const;
        const int &getGradeTosign() const;
        const int &getGradeToexecute() const;
        void    beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;
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
        class NotSignedException : public std::exception {
            public :
                virtual const char * what() const throw() {
                    return "form not signed";
                };
        };
        class OpeningFileException : public std::exception {
            public:
                virtual const char * what() const throw(){
                    return "error when opening the file";
                };
        };
};
std::ostream & operator<<(std::ostream &e, const AForm &src);

#endif