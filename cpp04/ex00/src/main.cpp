#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"


int main()
{
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        std::cout << meta->getType() << " " << std::endl;
        i->makeSound();
        j->makeSound();
        meta->makeSound();
    
        delete meta;
        delete j;
        delete i;
    }
    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* k = new WrongCat();

        std::cout << k->getType() << " " << std::endl;
        std::cout << meta->getType() << " " << std::endl;
        k->makeSound();
        meta->makeSound();
    
        delete meta;
        delete k;

    }
    return 0;
}