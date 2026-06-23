#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>
#include <string>

template <typename T>
void print_value(T a)
{
    std::cout << a << std::endl;
}

template <typename T , typename F>
void iter(T *a, const size_t len, F c)
{
    for (size_t i = 0; i < len; i++)
        c(a[i]);

}


#endif