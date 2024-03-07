#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

void get_file(std::string filename)
{
    std::string line;
    std::string date;
    float value;
    std::fstream database;
    database.open("test.csv");

    std::getline(database, line);
    std::istringstream stream(line);
    stream >> date >> value;

    line.erase(line.find('|'), 1);
    if (line.find('|'))
        std::cout << "error\n";
}