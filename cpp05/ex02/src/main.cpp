#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));
    try {
        // AForm ok("tata");
        Bureaucrat b1("president", 1);
        Bureaucrat b2("eli", 73);
        Bureaucrat b3("minion", 150);
        RobotomyRequestForm robot("Presidential");
        PresidentialPardonForm pardon("PardonForm");
        ShrubberyCreationForm shrub("ShrubForm");
        b3.signForm(robot);
        b1.signForm(robot);
        b2.executeForm(robot);
        b1.executeForm(robot);
        b1.executeForm(robot);
        b1.signForm(pardon);
        b1.signForm(shrub);
        b1.executeForm(pardon);
        b1.executeForm(shrub);
        std::cout << robot << std::endl;
        std::cout << shrub << std::endl;
        std::cout << pardon << std::endl;
    }
    catch(const std::exception &e) {
        std::cerr << "Exception catched : " << e.what() << std::endl;
    }
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << std::endl;
    return 0;
}

