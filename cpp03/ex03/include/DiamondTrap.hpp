#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    private :
        std::string _DiamondName;
    public :
        DiamondTrap();
        DiamondTrap(const std::string name);
        DiamondTrap(const DiamondTrap& copy);
        DiamondTrap& operator=(const DiamondTrap& other);
        ~DiamondTrap();
        void whoAmI();
        void attack(const std::string& target); //override;
};