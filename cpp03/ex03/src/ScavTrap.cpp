#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    _hitPoint = 100;
    _energy = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
    _hitPoint = 100;
    _energy = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap assignment operator called" << std::endl;
    return *this;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (_hitPoint <= 0)
        std::cout << "ScavTrap " << _name << " can't attack, he is dead." << std::endl;
    else if (_energy <= 0)
        std::cout << "ScavTrap " << _name << " can't attack, he has no energy left." << std::endl;
    else {
        std::cout << "ScavTrap " << _name << " attacks " << target 
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energy--;
    }
}