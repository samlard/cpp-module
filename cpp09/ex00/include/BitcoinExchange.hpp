#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

class BitcoinExchange {

    private:
        std::map<std::string, double> _btc;

    public: 
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange& operator=(const BitcoinExchange &src);
        bool parseCSV(const std::string &filename);
        bool find_price(std::string &filename);
    };

#endif