/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:55:18 by rastie            #+#    #+#             */
/*   Updated: 2024/01/18 19:23:05 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
	_hitP = 100;
	_energyP = 100;
	_attackP = 30;
	std::cout << "Default constructor called for FragTrap" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{	
	_hitP = 100;
	_energyP = 100;
	_attackP = 30;
	std::cout << "Parameter constructor called for FragTrap " << _name << std::endl;
}

FragTrap::FragTrap(FragTrap const & orig)
{
	*this = orig;
	std::cout << "Copy constructor called for FragTrap " << _name << std::endl;
}
FragTrap::~FragTrap(void)
{
	std::cout << "Destructor called for FragTrap " << _name << std::endl;
}


void FragTrap::highFivesGuys(void)
{
	if (!_hitP)
		std::cout << "FrapTrap " << _name << " is dead." << std::endl;
	else
		std::cout << "FrapTrap " << _name << " highfive everybody." << std::endl;
}

