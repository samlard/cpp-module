#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <sstream>
#include <iostream>

class RPN { 
    private : 
        std::stack<int> _stack;

    public : 
        RPN();
        ~RPN();
        RPN(const RPN &src);
        RPN &operator=(const RPN &src);
        bool execute(char *operationStr);
};


#endif