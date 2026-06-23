#include "Bureaucrat.hpp"

int main() {

    try {
        Bureaucrat Blop("Blop", 42);
        std::cout << Blop << std::endl;
        Blop.incrementGrade();
        std::cout << "After incrementation" << Blop << std::endl;
        Blop.decrementGrade();
        std::cout << "After decrementation" << Blop << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Error catch : " << e.what() << std::endl;
    }
    std::cout << "---------------------------------------" << std::endl;


    try {
        Bureaucrat boss("Boss", 0);
        std::cout << boss << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Error catch : " << e.what() << e.what() << std::endl;
    }
    std::cout << "---------------------------------------" << std::endl;


    try {
        Bureaucrat intern("Intern", 151);
        std::cout << intern << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Error catch : " << e.what() << std::endl;
    }
    std::cout << "---------------------------------------" << std::endl;


    try {
        Bureaucrat alice("Alice", 1);
        std::cout << alice << std::endl;
        alice.incrementGrade();
    }
    catch (const std::exception &e) {
        std::cerr << "Error catch : " << e.what() << std::endl;
    }
    std::cout << "---------------------------------------" << std::endl;


    try {
        Bureaucrat tom("Tom", 150);
        std::cout << tom << std::endl;
        tom.decrementGrade();
    }
    catch (const std::exception &e) {
        std::cerr << "Error catch : " << e.what() << std::endl;
    }
    std::cout << "---------------------------------------" << std::endl;
    return 0;
}
