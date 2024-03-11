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
void removeSpace(std::string &str)
{
    for (size_t i = 0; i < str.size(); i++)
        if (isspace(str[i]))
            str.erase(i--, 1);
}

BitcoinExchange::BitcoinExchange(void): _filename("data.csv")
{
    //this->initDataBase();
}

BitcoinExchange::BitcoinExchange(std::string fileData)
{
    _filename = fileData;
    //this->initDataBase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bitcoinExchange)
{
        *this = bitcoinExchange;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
    if (this == &rhs)
        return (*this);
    _data = rhs._data;
    _filename = rhs._filename;
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
    if (_fileDatabase.is_open())
        _fileDatabase.close();
    if (_fileEntry.is_open())
        _fileEntry.close();
}

void BitcoinExchange::initDataBase(void)
{
    std::string firstline;
    char *end = 0;

    _fileDatabase.open(_filename.c_str());

    if (!_fileDatabase.is_open())
        throw std::ios_base::failure("Couldn't open the database file");
    
    std::getline(_fileDatabase, firstline); //first line
    for (std::string line; std::getline(_fileDatabase, line);)
    {
        removeSpace(line);
        size_t delim = line.rfind(',');
        if (delim == std::string::npos)
        {
            std::cerr << "Bad input => " << line << "\n";
            return ;
        }
        std::string date = line.substr(0, delim);
        float value = static_cast<float>(std::strtod(line.substr(delim + 1).c_str(), &end));
        checkDate(date);
        if (value < 0)
            throw NegativeNumber();
        _data[date] = value;
    }
    _fileDatabase.clear();
	_fileDatabase.seekg(0);
    _fileDatabase.close();
}

void BitcoinExchange::exchange(std::string filename)
{
    std::string firstline;
    char *end = 0;

    _fileEntry.open(filename.c_str());

    if (!_fileEntry.is_open())
        throw std::ios_base::failure("Couldn't open the entry file");
    
    std::getline(_fileEntry, firstline); //first line
    for (std::string line; std::getline(_fileEntry, line);)
    {
        removeSpace(line);
        size_t delim = line.rfind('|');
        if (delim == std::string::npos)
        {
            std::cerr << "Bad input => " << line << "\n";
            continue ;
        }
        std::string date = line.substr(0, delim);
        float ammount = static_cast<float>(std::strtod(line.substr(delim + 1).c_str(), &end));
        try
        {
            std::string key(date);
            checkDate(date);
            std::map<std::string, float>::iterator it = _data.upper_bound(date);
            if (it == _data.begin())
               throw TooEarlyDate();
            key = (--it)->first;
            if (ammount < 0)
                throw NegativeNumber();
            if (ammount > 1000)
                throw NumberTooLarge();
            std::cout << date << " => " << ammount << " = " << ammount * _data[date] << "\n";            
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << '\n';
            continue ;
        }
        
    }
    _fileEntry.clear();
	_fileEntry.seekg(0);
    _fileEntry.close();
}

void BitcoinExchange::setDatabaseFilename(std::string filename)
{
    _filename = filename;
}
