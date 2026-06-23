#include "../include/RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Error: invalid number of arguments" << std::endl;
        return 1;
    }
    RPN rpn;
    if (!rpn.execute(argv[1]))
    {
        std::cout << "problem when parsing the input" << std::endl; 
        return 1;
    }
    return 0;
}