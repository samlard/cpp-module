#include "../include/Weapon.hpp"

Weapon::Weapon(std::string Weapon) : _type(Weapon)
{
    std::cout << "New weapon created type : " << _type << std::endl;
    return;
}
Weapon::~Weapon()
{
    std::cout << "Weapon destroyed" << std::endl;
    return;
}

const std::string &Weapon::get_type() const
{
    return this->_type;
}

void Weapon::setType(std::string str)
{
    this->_type = str;
}
