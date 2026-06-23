#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "../include/Weapon.hpp"

class HumanB
{
    private:
        std::string _name;
        Weapon *_weapon;

    public:
        HumanB(std::string str);
        ~HumanB();
        void setWeapon(Weapon &weapon);
        void attack();
};

#endif