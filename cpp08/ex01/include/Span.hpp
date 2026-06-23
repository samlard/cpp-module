#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

class SpanException : public std::exception
{
    public :
        virtual const char * what() const throw()
        {
            return "vector already full"; 
        }
};
class SpanToShortException : public std::exception
{
    public :
        virtual const char * what() const throw()
        {
            return "Not enough elements to make a span"; 
        }
};

class Span 
{
    private :
        unsigned int _maxSize;
        std::vector<int> _vec;
    public :
        Span(unsigned int N);
        ~Span();
        void addNumber(int nbr);
        int longestSpan() const;
        int shortestSpan() const;
        void iteratorAddNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};


#endif