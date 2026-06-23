#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <iostream>

class Weapon{
    private:
        std::string _type;
    public:
        Weapon(std::string weapon);
        ~Weapon();
        const std::string &get_type() const;
        void setType(std::string str);
};

#endif
