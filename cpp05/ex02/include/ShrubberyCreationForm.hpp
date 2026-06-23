#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    
    private :
        std::string _target;

    public :
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &src);
        ShrubberyCreationForm & operator=(const ShrubberyCreationForm &src);
        void execute(Bureaucrat const &executor) const;
};



#endif