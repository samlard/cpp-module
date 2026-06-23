#include "../include/Dog.hpp"
#include "../include/Brain.hpp"

Dog::Dog() : Animal("Dog") {
    _brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const std::string type) :  Animal(type){
    _brain = new Brain(type);
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete _brain;
}

Dog::Dog(const Dog& copy) : Animal(copy) {
    _brain = new Brain(*copy._brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other)
    {
        Animal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    std::cout << "Dog copy assignement operator called" << std::endl;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "WOUF WOUF" << std::endl;
}

Brain* Dog::getBrain() const{
    return _brain;
}