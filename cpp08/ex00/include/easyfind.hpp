#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <stdexcept>

class NotFoundException : public std::exception
{
    public : 
        virtual const char * what() const throw()
        {
            return "Value not found";
        }
};

template <typename T>
void easyfind(T &container, int value)
{
    typename T::iterator i;
    for (i = container.begin(); i != container.end(); i++)
    {
        if (*i == value)
        {
            std::cout << "value " << value << " found" << std::endl;
            return;
        }
    }
    throw NotFoundException();
};


#endif