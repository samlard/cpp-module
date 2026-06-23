#include "../include/ShrubberyCreationForm.hpp"
#include "fstream"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137), _target("default") {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target) {}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm
     &src) {
    if (this != &src)
    {
        AForm::operator=(src); 
        this->_target = src._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
    if (!this->getIsSigned())
        throw AForm::NotSignedException();
    else if (this->getGradeToexecute() < executor.getGrade())
        throw AForm::GradeTooLowException();
    else
    {
        std::ofstream file((_target + "_shrubbery").c_str());
        if (!file)
            throw AForm::OpeningFileException();
       file <<
        "          &&& &&  & &&\n"
        "      && &\\/&\\|& ()|/ @, &&\n"
        "      &\\/(/&/&||/& /_/)_&/_&\n"
        "   &() &\\/&|()|/&\\/ '%\" & ()\n"
        "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
        "&&   && & &| &| /& & % ()& /&&\n"
        " ()&_---()&\\&\\|&&-&&--%---()~\n"
        "     &&     |||\n"
        "             |||\n"
        "             |||\n"
        "             |||\n"
        "       , -=-~  .-^- _\n";
        file.close();
    }
}