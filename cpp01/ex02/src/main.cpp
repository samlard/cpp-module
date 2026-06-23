#include <iostream>

int main(void)
{
    // int *i;
    // int a = 42;
    // int &b;
    // b = a;
    std::string str = "HI THIS BRAIN";
    std::string *ptr = &str;
    std::string &ref = str; //une reference c'est comme un pointeur tjr dereference

    std::cout << "adress of str: " << &str << std::endl;
    std::cout << "adress of ptr" << &ptr << std::endl;
    std::cout << "adress of ref: " << &ref << std::endl;
    std::cout << "str content: " << str << std::endl;
    std::cout << "ptr content: " << *ptr << std::endl;
    std::cout << "ref content: " << ref << std::endl;

    *ptr = "HELLOW MISTER BRAIN";
    std::cout << "str content after change: " << str << std::endl;
    std::cout << "ptr content after change: " << *ptr << std::endl;
    std::cout << "ref content after change: " << ref << std::endl;

    ref = "coucou";
    std::cout << "str content after ref change: " << str << std::endl
              << "ptr content after ref change: " << *ptr << std::endl
              << "ref content after ref change: " << ref << std::endl;

    // i = &a;
    // std::cout << "value of i: " << *i << std::endl;
}
