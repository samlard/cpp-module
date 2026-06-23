#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"


int main() {
    const int size = 4;
    Animal* animals[size];

    animals[0] = new Dog();
    animals[1] = new Dog();
    animals[2] = new Cat();
    animals[3] = new Cat();

    std::cout << "\n--- Test makeSound() ---\n";
    for (int i = 0; i < size; ++i) {
        animals[i]->makeSound();
    }

    std::cout << "\n--- Test operator= pour Cat ---\n";
    Cat* cat1 = new Cat();
    Cat* cat2 = new Cat();

    cat1->getBrain()->setIdeas(0, "I want fish");
    cat2->getBrain()->setIdeas(0, "I want milk");

    *cat2 = *cat1;
    std::cout << "cat1 idea[0]: " << cat1->getBrain()->getIdeas(0) << std::endl;
    std::cout << "cat2 idea[0]: " << cat2->getBrain()->getIdeas(0) << std::endl;

    delete cat1;
    delete cat2;

    std::cout << "\n--- Deleting animals ---\n";
    for (int i = 0; i < size; ++i) {
        delete animals[i];
    }
    return 0;
}