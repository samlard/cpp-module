#include "Zombie.hpp"

int main()
{
    int N = 10;
    Zombie *horde = zombieHorde(N, "harley");
    if (!horde)
    {
        std::cerr << "problem whit horde allocation" << std::endl;
        return 1;
    }
    for (int i = 0; i < N; i++)
    {
        horde[i].announce();
    }
    delete[] horde;
    return 0;
}