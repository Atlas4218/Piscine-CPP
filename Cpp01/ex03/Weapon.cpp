#include "Weapon.hpp"

Weapon::Weapon(std::string str): type(str)
{
    std::cout << "Weapon constructor called" << std::endl;
}

Weapon::~Weapon()
{
        std::cout << "Weapon destructor called" << std::endl;
}

std::string &Weapon::getType(void)
{
    return (this->type);
}

Weapon::setType(std::string str)
{
    this->type = str;
}