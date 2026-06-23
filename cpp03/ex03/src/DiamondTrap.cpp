# include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), _DiamondName("default") {
    _hitPoint = FragTrap::_hitPoint;
    _energy = ScavTrap::_energy;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), _DiamondName(name) {
    _hitPoint = FragTrap::_hitPoint;
    _energy = ScavTrap::_energy;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy),  _DiamondName(copy._DiamondName) {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)   {
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->_DiamondName = other._DiamondName;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "My ClapTrap _name : " << getName() << std::endl << "My DiamondTrapname : " << _DiamondName << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}