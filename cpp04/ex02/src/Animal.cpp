#include "../include/Animal.hpp"

Animal::Animal() : _type("default") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string type) : _type(type) {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& copy) : _type(copy._type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other)
        this->_type = other._type;
    std::cout << "Animal copy assignement operator called" << std::endl;
    return *this;
}

const std::string &Animal::getType() const {
    return this->_type;
}

void Animal::makeSound() const{
    std::cout << "an animal make some nooise" << std::endl;
}


