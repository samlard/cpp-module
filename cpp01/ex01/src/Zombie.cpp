#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "Zombie created" << std::endl;
}

Zombie::Zombie(std::string str) : _name(str)
{
    std::cout << "Zombie created." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << _name << " destroyed." << std::endl;
}

void Zombie::announce()
{
    std::cout << get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

const std::string &Zombie::get_name() const
{
    return this->_name;
}

void Zombie::set_name(std::string str)
{
    this->_name = str;
}