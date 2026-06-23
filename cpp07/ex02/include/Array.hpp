#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <cstddef>

template <typename T>

class Array 
{
    private :
        T *_array;
        size_t _len;
    public :
        Array();
        ~Array();
        Array(unsigned int n);
        Array(const Array &src);
        Array &operator=(const Array &src);
        const T &operator[](size_t index)const;
        T &operator[](size_t index);
        size_t size()const;



};

class ArrayException : public std::exception
{
    public :
        const char * what() const throw(){
            return "Invalid index";
        };
};

#include "Array.tpp"

#endif