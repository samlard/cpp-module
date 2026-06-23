#include "../include/PmergeMe.hpp"

int main(int ac, char **argv)
{
    if (ac < 2)
    {
        std::cerr << "Error : not enough arguments" << std::endl;
        return 1;
    }
    PmergeMe pme;
    if (!pme.parseInput(ac, argv))
    {
        std::cerr << "Error : input not valid" << std::endl;
        return 1;
    }
    // pme.printBefore();
    std::clock_t start_vec = std::clock();
    pme.sortVector();
    std::clock_t end_vec = std::clock();
    // pme.printAfter();
    double duration_vec = double(end_vec - start_vec) / CLOCKS_PER_SEC * 1e6;
    std::cout << "Time to process a range of " << pme.getVectorSize()
              << " elements with std::vector : " << duration_vec << " us" << std::endl;
    std::clock_t start_deque = std::clock();
    pme.sortDeque();
    std::clock_t end_deque = std::clock();
    double duration_deque = double(end_deque - start_deque) / CLOCKS_PER_SEC * 1e6;
    std::cout << "Time to process a range of " << pme.getDequeSize()
              << " elements with std::deque : " << duration_deque << " us" << std::endl;
    return 0;
}