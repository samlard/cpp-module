#include "../include/RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN &src) : _stack(src._stack){}

RPN& RPN::operator=(const RPN &src) {
    if (this != &src)
        _stack = src._stack;
    return *this;
}

bool RPN::execute(char *operationStr)
{
    std::stringstream ss(operationStr);
    std::string token;
    while (ss >> token)
    {
        if (token.length() == 1 && std::isdigit(token[0]))
            _stack.push(token[0] - '0');

        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (_stack.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return false;
            }
            int b = _stack.top(); 
            _stack.pop();
            int a = _stack.top();
            _stack.pop();
            int result;
            if (token == "+")
                result = a + b;
            else if (token == "-")
                result = a - b;
            else if (token == "*")
                result = a * b;
            else
            {
                if (b == 0)
                {
                    std::cerr << "Error" << std::endl;
                    return false;
                }
                result = a / b;
            }
            _stack.push(result);
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return false;
        }
    }
    if (_stack.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return false;
    }
    std::cout << _stack.top() << std::endl;
    return true;
}
