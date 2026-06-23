#include "Span.hpp"

int main()
{
    try
    {
        std::cout << "===== Test Span simple =====" << std::endl;
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;

        std::cout << "\n===== Test Span plein =====" << std::endl;
        sp.addNumber(42); // doit lever une exception
    }
    catch (const SpanException &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    catch (const SpanToShortException &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n===== Test Span trop court =====" << std::endl;
        Span sp2(3);
        sp2.addNumber(10);
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl; // exception
    }
    catch (const SpanToShortException &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n===== Test ajout d'une plage =====" << std::endl;
        Span sp3(10);
        std::vector<int> numbers;
        for (int i = 1; i <= 10; ++i)
            numbers.push_back(i * 3);

        sp3.iteratorAddNumber(numbers.begin(), numbers.end());
        std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp3.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
