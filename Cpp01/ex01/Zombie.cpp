#include "Zombie.hpp"

Zombie::Zombie(std::string name): _name(name)
{
	std::cout << "Zombie constructor called" << std::endl;
}

Zombie::~Zombie()
{
    	std::cout << "Zombie destructor called" << std::endl;
}

Zombie::annouce(void)
{
    std::cout << this->_name <<  ": BraiiiiiiinnnzzzZ..." << std::endl;

}

Zombie::setName(std::string name)
{
	this->_name = name;
}