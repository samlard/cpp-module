#include "../include/Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug() {
    std::cout << "[ DEBUG ]" << std::endl;
}

void Harl::info() {
    std::cout << "[ INFO ]" << std::endl;
}

void Harl::warning(){
     std::cout << "[ WARNING ]" << std::endl;
}

void Harl::error() {
    std::cout << "[ ERROR ]" << std::endl;
}

void Harl::complain(std::string level) {
    std::string tab[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*fct[])() = {
        &Harl::debug, &Harl::info, &Harl::warning, &Harl::error
    };
    for(int i = 0; i < 4; i++)
    {
        if (level == tab[i])
        {
            (this->*fct[i])();
            return;
        }
    }
    std::cout << "Not a good level" << std::endl;
}