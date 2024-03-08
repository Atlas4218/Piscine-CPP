#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

class BitcoinExchange
{
private:
    std::string _filename;
    std::map<std::string, float> _data;
    std::fstream _fileDatabase;
    std::fstream _fileEntry;

    
public:
    BitcoinExchange(void);
    BitcoinExchange(std::string fileData);
    BitcoinExchange(const BitcoinExchange& bitcoinExchange);
    BitcoinExchange &operator=(const BitcoinExchange &rhs);
    ~BitcoinExchange();

    void initDataBase(void);

    void exchange(std::string filename);

    class BadDateFormat: public std::exception
    {
    public:
            virtual const char* what() const throw() {return "Bad Date Format";}
    };

    class InvalidDate: public std::exception
    {
    public:
            virtual const char* what() const throw() {return "Bad Date Value";}
    };
    class BadBtcValue: public std::exception
    {
    public:
            virtual const char* what() const throw() {return "Bad monetary Value";}
    };
};