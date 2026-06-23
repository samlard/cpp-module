#include "../include/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    _hitPoint = 100;
    _energy = 100;
    _attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
    _hitPoint = 100;
    _energy = 100;
    _attackDamage = 30;
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) {
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "FragTrap assignment operator called" << std::endl;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFiveGuys() {
    std::cout << "HIGH FIVE !" << std::endl;
}