#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}

Span::~Span(){}

void Span::addNumber(int nbr)
{
    if (this->_vec.size() >= _maxSize)
        throw SpanException();
    _vec.push_back(nbr);
}

int Span::longestSpan() const
{
    if (_vec.size() < 2)
        throw SpanToShortException();
    int min = *std::min_element(_vec.begin(), _vec.end());
    int max = *std::max_element(_vec.begin(), _vec.end());
    return max - min;
}

int Span::shortestSpan() const
{
    if (_vec.size() < 2)
        throw SpanToShortException();
    std::vector<int> copy = _vec;
    std::sort(copy.begin(), copy.end());
    int minspan = copy[1] - copy[0];
    for (size_t i =2; i < copy.size(); i++)
    {
        int span = copy[i] - copy[i - 1];
        if (span < minspan)
            minspan = span;
    }
    return minspan;
}

void Span::iteratorAddNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    for (std::vector<int>::iterator it = begin; it != end; ++it)
        addNumber(*it);
}
