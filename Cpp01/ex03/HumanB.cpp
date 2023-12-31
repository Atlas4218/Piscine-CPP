#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
    std::cout << "HumanB constructor called" << std::endl;
}

HumanB::~HumanB()
{
    std::cout << "HumanB destructor called" << std::endl;
}

HumanB::attack()
{
    if (!this->_weapon || this->_weapon == "")
        std::cout << this->_name << "has no weapon" << std::endl;
    else
        std::cout << this->_name << "attacks with their" << this->_weapon.getType() << std::endl;
}

HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}