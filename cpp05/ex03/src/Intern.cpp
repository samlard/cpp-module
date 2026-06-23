#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &src) {
    (void)src;
}

Intern & Intern::operator=(const Intern &src){
    (void)src;
    return *this;
}

static AForm * createrobot(const std::string &target){
    return new RobotomyRequestForm(target);
}

static AForm * createshrub(const std::string &target){
    return new ShrubberyCreationForm(target);
}

static AForm * createpresidential(const std::string &target){
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeform(const std::string &name, const std::string &target) const{
    std::string tab[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    AForm *(*fct[])(const std::string &) = {
        createpresidential, createrobot, createshrub};
    for(int i = 0; i < 3; i++)
    {
        if (name == tab[i])
        {
            std::cout << "Intern create form " << name << std::endl;
            return fct[i](target);
        }
    }
    throw Intern::InvalidFormException();
    return NULL;
}

