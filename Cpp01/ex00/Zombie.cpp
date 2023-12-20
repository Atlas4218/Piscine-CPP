#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	std::cout << "Zombie constructor called" << std::endl;
}

Zombie::~Zombie()
{
    	std::cout << "Zombie destructor called" << std::endl;
}

Zombie::annouce(void)
{
    std::cout << this->name <<  ": BraiiiiiiinnnzzzZ..." << std::endl;

}