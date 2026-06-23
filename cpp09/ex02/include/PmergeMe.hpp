#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <stdexcept>
#include <ctime>
#include <climits>
#include <algorithm>

class PmergeMe
{
    private:
        std::vector<int> _vec;
        std::deque<int>  _deque;
        void fordJohnsonVector(std::vector<int> &v);
        void fordJohnsonDeque(std::deque<int> &d);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);
        ~PmergeMe();
        bool parseInput(int ac, char **av);
        void sortVector();
        void sortDeque();
        void printBefore() const;
        void printAfter() const;
        size_t getVectorSize() const;
        size_t getDequeSize() const;
};

#endif