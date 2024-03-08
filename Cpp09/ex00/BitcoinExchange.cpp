#include "BitcoinExchange.hpp"

bool checkDateFormat(std::string date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return true;
    for (size_t i = 0; i < date.size(); i++)
        if (!isdigit(date[i]) && i != 4 && i != 7)
            return true;
    return false;
}
bool isLeapYear(int year)
{
    return ((!(year % 100) || !(year % 4)) && year % 400);
}
bool checkDateValidity(std::string date)
{
    unsigned int year, month, day;
    char *end = 0;
    year = std::strtol(date.substr(0,4).c_str(), &end, 10);
    month = std::strtol(date.substr(5,2).c_str(), &end, 10);
    day = std::strtol(date.substr(8).c_str(), &end, 10);
    unsigned int nbDayOfMonth[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (month >= 1 && month <= 12 &&  day >= 1 && day <= nbDayOfMonth[month - 1]);
}
void checkDate(std::string date)
{
    if (checkDateFormat(date))
        throw BitcoinExchange::BadDateFormat();
    if (!checkDateValidity(date))
        throw BitcoinExchange::InvalidDate();
}

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(std::string fileData)
{
    _filename = fileData;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bitcoinExchange)
{
    if (this != &bitcoinExchange)
        *this = bitcoinExchange;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
    _data = rhs._data;
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
    if (_fileDatabase.is_open())
        _fileDatabase.close();
}

void BitcoinExchange::initDataBase(void)
{
    std::map<std::string, float> _data;
    std::string firstline;
    char *end = 0;

    _fileDatabase.open("data.csv");

    if (!_fileDatabase.is_open())
        throw std::ios_base::failure("Couldn't open the database file");
    
    std::getline(_fileDatabase, firstline); //first line
    for (std::string line; std::getline(_fileDatabase, line);)
    {
        size_t delim = line.find(',');
        std::string date = line.substr(0, delim);
        float value = static_cast<float>(std::strtod(line.substr(delim + 1).c_str(), &end));
        checkDate(date);
        if (value < 0)
            throw NegativeNumber();
        _data[date] = value;
    }
    _fileDatabase.clear();
	_fileDatabase.seekg(0);
}

void BitcoinExchange::exchange(std::string filename)
{
    std::map<std::string, float> _data;
    std::string firstline;
    char *end = 0;

    _fileDatabase.open("data.csv");

    if (!_fileDatabase.is_open())
        throw std::ios_base::failure("Couldn't open the database file");
    
    std::getline(_fileDatabase, firstline); //first line
    for (std::string line; std::getline(_fileDatabase, line);)
    {
        size_t delim = line.find(',');
        std::string date = line.substr(0, delim);
        float value = static_cast<float>(std::strtod(line.substr(delim + 1).c_str(), &end));
        try
        {
            checkDate(date);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        if (value < 0)
            throw NegativeNumber();
        if (value > 1000)
            throw NumberTooLarge();
        _data[date] = value;
    }
    _fileDatabase.clear();
	_fileDatabase.seekg(0);
}