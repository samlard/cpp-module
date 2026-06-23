#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5), _target("default") {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), _target(src._target) {}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
    if (this != &src)
    {
        AForm::operator=(src); 
        this->_target = src._target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const{
    if (!this->getIsSigned())
        throw AForm::NotSignedException();
    else if (this->getGradeToexecute() < executor.getGrade())
        throw AForm::GradeTooLowException();
    else
        std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}