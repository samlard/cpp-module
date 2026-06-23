#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    
    private :
        std::string _target;

    public :
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &src);
        RobotomyRequestForm & operator=(const RobotomyRequestForm &src);
        void execute(Bureaucrat const &executor) const;
};





#endif