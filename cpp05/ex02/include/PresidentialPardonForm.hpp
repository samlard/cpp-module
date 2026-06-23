#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {

    private :
        std::string _target;

    public :
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &src);
        PresidentialPardonForm & operator=(const PresidentialPardonForm &src);
        void execute(Bureaucrat const &executor) const;
};

#endif