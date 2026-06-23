#include "iter.hpp"

int main(void)
{
    int tab[3] = {1,2,3};
    std::string tas[4] = {"coucou", "ca", "va", "toi"};
    ::iter(tab, 3, ::print_value<int>);
    ::iter(tas, 4, ::print_value<std::string>);
}