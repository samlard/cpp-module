#ifndef INTERN_HPP
# define INTERN_hpp
#include "AForm.hpp"

class Intern {
    public :
        Intern();
        ~Intern();
        Intern(const Intern &src);
        Intern & operator=(const Intern &src);
        AForm * makeform(const std::string &name, const std::string &target) const;
        class InvalidFormException : public std::exception {
            public :
                virtual const char* what() const throw() {
                    return "Form name doesn't mach any form";
                };
        };
};

#endif