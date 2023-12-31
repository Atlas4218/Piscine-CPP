/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:04:41 by rastie            #+#    #+#             */
/*   Updated: 2023/12/31 14:50:47 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name): _name(name)
{
	std::cout << "Zombie " << this->_name << " constructor called" << std::endl;
}

Zombie::~Zombie()
{
    	std::cout << "Zombie " << this->_name << " destructor called" << std::endl;
}

Zombie::annouce(void)
{
    std::cout << this->_name <<  ": BraiiiiiiinnnzzzZ..." << std::endl;

}

Zombie::setName(std::string name)
{
	this->_name = name;
}