#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

#include <iostream>
#include "DiamondTrap.hpp"

int main() {
    // Création d'un DiamondTrap
    DiamondTrap dt1("Albert");

    // Affichage des messages du constructeur
    std::cout << "DiamondTrap dt1 créé\n";

    // Utilisation de fonctions héritées
    dt1.attack("Target1");
    dt1.beRepaired(20);
    dt1.takeDamage(15);

    // Utilisation des fonctions spécifiques
    dt1.whoAmI();

    // Test du constructeur par copie
    DiamondTrap dt2(dt1);
    std::cout << "DiamondTrap dt2 (copie de dt1) créé\n";
    dt2.whoAmI();

    // Test de l'opérateur d'affectation
    DiamondTrap dt3("Beta");
    dt3 = dt1;
    std::cout << "DiamondTrap dt3 après affectation de dt1\n";
    dt3.whoAmI();

    // Fin du programme → destructeurs appelés dans l'ordre inverse
    return 0;
}

