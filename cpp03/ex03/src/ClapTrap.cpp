#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _name("default"), _hitPoint(10), _energy(10), _attackDamage(0) {
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap (const std::string name)
    :  _name(name), _hitPoint(10), _energy(10), _attackDamage(0) {
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap()   {
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) 
    :   _name(other._name), _hitPoint(other._hitPoint), _energy(other._energy), 
        _attackDamage(other._attackDamage)  {
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)    {
    if (this != &other) {
        _name = other._name;
        _hitPoint = other._hitPoint;
        _energy = other._energy;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (_hitPoint <= 0)
        std::cout << "ClapTrap " << _name << " can't attacks he is dead" << std::endl;
    else if (_energy <= 0)
         std::cout << "ClapTrap " << _name << " can't attacks he has no more energy point" << std::endl;
    else
    {
        std::cout << "ClapTrap " << _name << " attacks " << target 
        << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energy--;
    }
}

void ClapTrap::takeDamage(unsigned int amount)  {
    if ((int)amount <= 0)
        std::cout << "ClapTrap " << _name << " can't take " << "negative damage!" << std::endl;
    else if (_hitPoint <= 0)
        std::cout << "ClapTrap " << _name << " can't take dammage anymore he is dead" << std::endl;
    else
    {
        std::cout << "ClapTrap " << _name << " take " << amount
        << " points of damage!" << std::endl;
        _hitPoint -= amount;
    }
}

void ClapTrap::beRepaired(unsigned int amount)  {
    if ((int)amount <= 0)
        std::cout << "ClapTrap " << _name << " can't berepaired with negative amount!" << std::endl;
    else if (_hitPoint <= 0)
        std::cout << "ClapTrap " << _name << " can't be repaired because he is dead" << std::endl;
    else if (_energy <=0)
        std::cout << "ClapTrap " << _name << " can't be repaired because he has no more energy" << std::endl;
    else
    {
        std::cout << "ClapTrap " << _name << " repaired itself and gained " << amount << " points of energy" << std::endl;
        _hitPoint += amount;
        _energy--;
    }
}

const std::string &ClapTrap::getName() const {
    return this->_name;
}