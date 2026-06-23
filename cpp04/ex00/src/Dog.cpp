#include "../include/Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const std::string type) :  Animal(type){
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy) {
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other)
        Animal::operator=(other);
    std::cout << "Dog copy assignement operator called" << std::endl;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "WOUF WOUF" << std::endl;
}