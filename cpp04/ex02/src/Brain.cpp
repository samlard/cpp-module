#include "../include/Brain.hpp"
#include "../include/Animal.hpp"

Brain::Brain() {
    for (int i = 0; i < 100; i++)
        _ideas[i] = "default ideas";
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const std::string ideas) {
    for (int i = 0; i < 100; i++)
        _ideas[i] = ideas;
    std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& copy) {
    for (int i = 0; i < 100; i++)
       this-> _ideas[i] = copy._ideas[i];
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this-> _ideas[i] = other._ideas[i];
    }
    std::cout << "Brain copy assignement operator called" << std::endl;
    return *this;
}

void Brain::setIdeas(int index, const std::string& idea) {
    if (index >= 0 && index < 100)
        _ideas[index] = idea;
    else
        std::cerr << "Invalid index for idea" << std::endl;
}

std::string Brain::getIdeas(int index) const {
    if (index >= 0 && index < 100)
        return _ideas[index];
    else {
        std::cerr << "Invalid index for idea" << std::endl;
        return "";
    }
}
