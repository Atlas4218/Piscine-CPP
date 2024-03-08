#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


bool checkDateFormat(std::string date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return true;
    for (int i = 0; i < date.size(); i++)
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
    year = std::strtol(date.substr(8).c_str(), &end, 10);
    int nbDayOfMonth[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (month >= 1 && month <= 12 &&  day >= 1 && day <= nbDayOfMonth[month - 1])


}
void checkDate(std::string date)
{
    if (checkDateFormat(date))
        throw BadDateFormat();
    if (checkDateValidity(date))
        throw InvalidDate();
}

void get_file(std::string filename)
{
    std::map<std::string, float> _data;
    std::string line;
    std::string date;
    float value;
    std::fstream database;
    char *end = 0;
    database.open("test.csv");

    std::getline(database, line);

    //parsing de  ligne
    char separator;
    size_t sep = line.find(separator);
    date = line.substr(0, sep);
    value = static_cast<float>(std::strtod(line.substr(sep + 1).c_str(), &end));
    checkDate(date);
    _data[date] = value;


    line.erase(line.find('|'), 1);
    if (line.find('|'))
        std::cout << "error\n";
}