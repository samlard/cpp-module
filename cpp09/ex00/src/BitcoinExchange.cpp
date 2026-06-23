#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src){
    _btc = src._btc;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &src){
    if (this != &src)
    {
        _btc = src._btc;
    }
    return *this;
}

static std::string trim(const std::string& str)
{
    const std::string whitespace = " \t\n\r";
    size_t start = str.find_first_not_of(whitespace);
    if (start == std::string::npos)
        return "";
    size_t end = str.find_last_not_of(whitespace);
    return str.substr(start, end - start + 1);
}

static bool is_bisextil_year(int year)
{
    if (year % 4 != 0)
        return false;
    if (year % 100 != 0)
        return true;
    if (year % 400 == 0)
        return true;
    return false;
}

static bool is_valid_day(int year, int month, int day)
{
    int max_days;

    switch (month)
    {
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:
            max_days = 31;
            break;
        case 4: case 6: case 9: case 11:
            max_days = 30;
            break;
        case 2:
            max_days = is_bisextil_year(year) ? 29 : 28;
            break;
        default:
            return false;
    }
    return (day <= max_days);
}

static bool is_valid_date(std::string &dateStr)
{
    if (dateStr.length() != 10)
        return false;
    if (dateStr[4] != '-' || dateStr[7] != '-')
        return false;
    int year, month, day;
    char sep1, sep2;
    std::stringstream ss(dateStr.c_str());
    ss >> year >> sep1 >> month >> sep2 >> day;
    if (!ss || sep1 != '-' || sep2 != '-')
        return false;
    char extra;
    if (ss >> extra)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    if (year < 0)
        return false;
    if (!is_valid_day(year, month, day))
        return false;
    return true;
}

static bool is_valid_btc_price(std::string &priceStr, double &price)
{
    std::stringstream ss(priceStr);

    if (!(ss >> price))
        return false;
    char rest;
    if (ss >> rest)
        return false;
    if (price < 0)
        return false;
    return true;
}

static bool is_valid_value(std::string &valueStr, double &value)
{
    std::stringstream ss(valueStr);

    if (!(ss >> value))
    {
        std::cerr << "Error: invalid number." << std::endl;
        return false;
    }
    char rest;
    if (ss >> rest)
    {
        std::cerr << "Error: invalid number." << std::endl;
        return false;
    }
    if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}


bool BitcoinExchange::find_price(std::string &filename)
{
    if (_btc.empty())
    {
        std::cerr << "Error: database empty" << std::endl;
        return false;
    }
    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cerr << "Error: could not open file -> " << filename << std::endl;
        return false;
    }
    std::string line;
    std::getline(infile, line);
    while (std::getline(infile, line))
    {
        line = trim(line);
         if (line.empty())
            continue;
        size_t sep = line.find('|');
        if (sep == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string dateStr = trim(line.substr(0, sep));
        std::string valueStr = trim(line.substr(sep + 1));
        double value;
        if (!is_valid_date(dateStr))
        {
            std::cerr << "Error: invalid date -> " << dateStr << std::endl;
            continue;
        }
        if (!is_valid_value(valueStr, value))
            continue;
        std::map<std::string, double>::iterator it = _btc.lower_bound(dateStr);
        if (it == _btc.end() || it->first > dateStr)
        {
            if (it == _btc.begin())
            {
                std::cerr << "Error: no available price for date -> " << dateStr << std::endl;
                continue;
            }
            --it;
        }
        double btc_price = it->second;
        double result = value * btc_price;
        std::cout << dateStr << " => " << value << " = " << result << std::endl;
    }
    return true;
}


bool BitcoinExchange::parseCSV(const std::string &filename){
    std::ifstream file(filename.c_str());
    if (!file)
    {
        std::cerr << "Error when trying opening the file : " << filename << std::endl;
        return false; 
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        line = trim(line);
        size_t comma = line.find(',');
        if (comma == std::string::npos)
            continue;
        std::string dateStr  = trim(line.substr(0, comma));
        std::string priceStr = trim(line.substr(comma + 1, std::string::npos));
        double price;
        if (!is_valid_date(dateStr))
            continue;
        if (!is_valid_btc_price(priceStr, price))
            continue;
        _btc[dateStr] = price;
    }
    return true;
}

