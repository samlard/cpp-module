#include "../include/HumanB.hpp"

HumanB::HumanB(std::string str) : _name(str), _weapon(NULL)
{
    std::cout << "HumanB created and named: " << _name << std::endl;
    return ;
}

HumanB::~HumanB()
{
    std::cout << "HumanB named" << _name << "destroyed" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}
void HumanB::attack()
{
    if (_weapon)
        std::cout << _name << " attack with " << _weapon->get_type() << std::endl;
    else 
         std::cout << _name << " is not armed" << std::endl;
}