#include <vector>
#include <list>
#include <deque>

#include "easyfind.hpp"

int main()
{
    std::vector<int> v;
    std::list<int>   l;
    std::deque<int>  d;

    // Remplissage des containers
    for (int i = 0; i < 5; ++i)
    {
        v.push_back(i * 10);   // 0, 10, 20, 30, 40
        l.push_back(i + 1);    // 1, 2, 3, 4, 5
        d.push_back(i);        // 0, 1, 2, 3, 4
    }

    std::cout << "=== TEST VECTOR ===" << std::endl;
    try
    {
        easyfind(v, 20);
        std::cout << "20 found in vector" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        easyfind(v, 99);
        std::cout << "99 found in vector" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== TEST LIST ===" << std::endl;
    try
    {
        easyfind(l, 3);
        std::cout << "3 found in list" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n=== TEST DEQUE ===" << std::endl;
    try
    {
        easyfind(d, 4);
        std::cout << "4 found in deque" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        easyfind(d, -1);
        std::cout << "-1 found in deque" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
