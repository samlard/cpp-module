#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Form form1("presidential form", 1, 2);
        std::cout << form1 << std::endl;
        Form form2("basic form", 100, 0);
    }
    catch(const std::exception &e) {
        std::cerr << "Exception catched : " << e.what() << std::endl;
    }
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << std::endl;

    try {
        Form form1("presidential form", 1, 2);
        Bureaucrat b1("vice president", 2);
        Bureaucrat b2("president", 1);
        std::cout << form1 << std::endl;
        std::cout << b1 << std::endl;
         std::cout << b2 << std::endl;
        b1.signForm(form1);
        b2.signForm(form1);
    }
    catch (const std::exception &e) {
        std::cerr << "Exception catched : " << e.what() << std::endl;
    }
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << std::endl;
    return 0;
}

