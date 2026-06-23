#include "ScavTrap.hpp"

int main() {
    {
        std::cout << "=== Test ClapTrap ===" << std::endl;

        ClapTrap ct1("Albert");
        ClapTrap ct2("Norbert");

        ct1.attack("target1");
        ct2.attack("target2");

        std::cout << "\n--- Test dégâts ---" << std::endl;
        ct1.takeDamage(8);
        ct1.takeDamage(5);
        ct2.takeDamage(4);

        std::cout << "\n--- Test réparation ---" << std::endl;
        ct1.beRepaired(5);
        ct2.beRepaired(2);

        std::cout << "\n--- Test énergie ---" << std::endl;
        for (int i = 0; i < 10; i++) {
          ct2.attack("Dummy");
        }
    }
    std::cout << "\n=== FIN DES TESTS CLAPTRAP ===" << std::endl;
    {

        std::cout << "=== Test ScavTrap ===" << std::endl;

        ScavTrap ct1("Albert");
        ScavTrap ct2("Norbert");

        ct1.attack("target1");
        ct2.attack("target2");

        std::cout << "\n--- Test guardgate  ---" << std::endl;
        ct1.guardGate();
        ct1.guardGate();

        std::cout << "\n--- Test dégâts ---" << std::endl;
        ct1.takeDamage(90);
        ct1.takeDamage(10);
        ct2.takeDamage(-4);

        std::cout << "\n--- Test réparation ---" << std::endl;
        ct1.beRepaired(5);
        ct2.beRepaired(2);

        std::cout << "\n--- Test énergie ---" << std::endl;
        for (int i = 0; i < 50; i++) {
          ct2.attack("Dummy");
        }
    }
    return 0;
}
