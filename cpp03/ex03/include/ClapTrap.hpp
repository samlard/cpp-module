#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>


class ClapTrap
{
    protected :
        std::string _name;
        int _hitPoint;
        int _energy;
        int _attackDamage;

    public :
        ClapTrap();
        ClapTrap(const std::string name);
        ~ClapTrap();
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        const std::string &getName() const;
};

#endif