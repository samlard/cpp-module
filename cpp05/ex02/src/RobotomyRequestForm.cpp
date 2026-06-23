#include "../include/RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45), _target("default") {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), _target(src._target) {}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
    if (this != &src)
    {
        AForm::operator=(src); 
        this->_target = src._target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const{
    if (!this->getIsSigned())
        throw AForm::NotSignedException();
    else if (this->getGradeToexecute() < executor.getGrade())
        throw AForm::GradeTooLowException();
    else
    {
        std::cout << _target << " DRIIIIIINNG" << std::endl;
        if (rand() % 2 == 0)
            std::cout << _target << " has been robotomized" << std::endl;
        else
            std::cout << "robotomize failed" << std::endl;
    }
}