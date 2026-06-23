#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("default") {
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type) : _type(type) {
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) : _type(copy._type) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other)
        this->_type = other._type;
    std::cout << "WrongAnimal copy assignement operator called" << std::endl;
    return *this;
}

const std::string &WrongAnimal::getType() const {
    return this->_type;
}

void WrongAnimal::makeSound() const{
    std::cout << "an WrongAnimal make some nooise" << std::endl;
}

