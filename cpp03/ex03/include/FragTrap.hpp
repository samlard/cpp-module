#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
#include "../include/ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

    public :
        FragTrap();
        FragTrap(const std::string name);
        ~FragTrap();
        FragTrap(const FragTrap& copy);
        FragTrap& operator=(const FragTrap& other);
        void highFiveGuys(void);
};

#endif