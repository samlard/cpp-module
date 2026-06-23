#include "../include/BitcoinExchange.hpp"


int main(int ac, char **argv)
{
    if (ac != 2)
    {
        std::cerr << "invalid nbr of arguments" << std::endl;
        return 1;
    }
    BitcoinExchange b;
    if (!b.parseCSV("data.csv"))
    {
        std::cerr << "Error when trying parse the data.csv" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    b.find_price(filename);
    return 0;
}