#include "../include/HumanA.hpp"

HumanA::HumanA(std::string str, Weapon &weapon) : _name(str), _weapon(weapon)
{
    std::cout << "HumanA created and named: " << _name << " armed with: " << _weapon.get_type() << std::endl;
    return;
}


HumanA::~HumanA()
{
    std::cout << "HumanA named: " << _name << " destroyed" << std::endl;
    return;
}

const std::string &HumanA::get_weapon() const
{
    return this->_weapon.get_type();
}

void HumanA::attack()
{
    std::cout << _name << " attack with " << _weapon.get_type() << std::endl;
}

void HumanA::setWeapon(Weapon &weapon)
{
    this->_weapon = weapon;
}

