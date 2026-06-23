#include "../include/Cat.hpp"
#include "../include/Brain.hpp"

Cat::Cat() : Animal("Cat") , _brain(new Brain) {
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const std::string type) :  Animal(type), _brain(new Brain(type)) {
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete _brain;
}

Cat::Cat(const Cat& copy) : Animal(copy),  _brain(new Brain(*copy._brain)) {
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other)
    {
        Animal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    std::cout << "Cat copy assignement operator called" << std::endl;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "MIAOUUU" << std::endl;
}

Brain* Cat::getBrain() const{
    return _brain;
}