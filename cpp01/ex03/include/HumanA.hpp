#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        Weapon &_weapon;
    public:
        HumanA(std::string _name, Weapon &weapon);
        ~HumanA();
        const std::string &get_weapon() const;
        void attack();
        void setWeapon(Weapon &Weapon);
        
};

#endif
