#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <stdexcept>

class Form;

class Bureaucrat {
    private :
        const std::string _name;
        int _grade;
    public :
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat & operator=(const Bureaucrat &src);
        const std::string &getName() const;
        const int &getGrade() const;
        void    incrementGrade();
        void    decrementGrade();
        void    signForm(Form &form);

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
std::ostream & operator<<(std::ostream &e, const Bureaucrat &src);

#endif