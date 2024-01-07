/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:04:41 by rastie            #+#    #+#             */
/*   Updated: 2024/01/07 16:44:40 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Zombie constructor called" << std::endl;
}

Zombie::~Zombie()
{
    	std::cout << "Zombie destructor called" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->_name <<  ": BraiiiiiiinnnzzzZ..." << std::endl;

}

void Zombie::setName(std::string name)
{
	this->_name = name;
}