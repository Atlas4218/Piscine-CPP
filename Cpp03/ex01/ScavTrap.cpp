/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:24:08 by rastie            #+#    #+#             */
/*   Updated: 2024/01/19 15:39:44 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	_hitP = 100;
	_energyP = 50;
	_attackP = 20;
	std::cout << "ScavTrap default constuctor called" << std::endl;
}


ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	_hitP = 100;
	_energyP = 50;
	_attackP = 20;
	std::cout << "Parameter constructor called for ScavTrap " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& orig)
{
	*this = orig;
	std::cout << "Parameter constructor called for ScavTrap " << _name << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << _name << " destuctor called" << std::endl;
}

void ScavTrap::attack(std::string target)
{
	if (_hitP && _energyP)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackP << " points of damage!" << std::endl;
		_energyP -= 1;
		return ;
	}
	if (!_hitP)
		std::cout << "ScavTrap " << _name << " is dead." << std::endl;
	else if (!_energyP)
		std::cout << "ScavTrap " << _name << " doesn't have energy left." << std::endl;
}


void ScavTrap::guardGate(void)
{
	if (!_hitP)
		std::cout << "ScavTrap " << _name << " is dead." << std::endl;
	else
		std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}

