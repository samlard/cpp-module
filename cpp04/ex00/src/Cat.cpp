#include "../include/Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const std::string type) :  Animal(type){
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy) {
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other)
        Animal::operator=(other);
    std::cout << "Cat copy assignement operator called" << std::endl;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "MIAOUUU" << std::endl;
}