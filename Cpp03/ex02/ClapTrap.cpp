/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:53:59 by rastie            #+#    #+#             */
/*   Updated: 2024/01/17 15:23:11 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	_hitP = 10;
	_energyP = 10;
	_attackP = 0;
	std::cout << "Default constructor called for ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitP(10), _energyP(10), _attackP(0)
{
	std::cout << "Parameter constructor called for ClapTrap " << _name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & orig)
{
	*this = orig;
	std::cout << "Copy constructor called for ClapTrap " << _name << std::endl;
}
ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called for ClapTrap " << _name << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_hitP = rhs._hitP;
		_energyP = rhs._energyP;
		_attackP = rhs._attackP;
	}
	std::cout << "Copy assignment operator called for ClapTrap " << _name << std::endl;
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (_hitP && _energyP)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackP << " points of damage!" << std::endl;
		_energyP -= 1;
		return ;
	}
	if (!_hitP)
		std::cout << "ClapTrap " << _name << " is dead." << std::endl;
	else if (!_energyP)
		std::cout << "ClapTrap " << _name << " doesn't have energy left." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!_hitP)
	{
		std::cout << "Stop, Stop! ClapTrap " << _name << " is already dead." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " take " << amount << " damages." << std::endl;
	if (amount > _hitP)
		_hitP = 0;
	else
		_hitP -= amount;
	if (!_hitP)
		std::cout << "ClapTrap " << _name << " is dead." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitP && _energyP)
	{
		std::cout << "ClapTrap " << _name << " gain " << amount << " life points." << std::endl;
		_energyP -= 1;
		_hitP += amount;
		return ;
	}
	if (!_hitP)
		std::cout << "ClapTrap " << _name << " was already dead. It's to late to save it." << std::endl;
	else if (!_energyP)
		std::cout << "ClapTrap " << _name << " doesn't have energy left." << std::endl;
}

std::string ClapTrap::getName(void)
{
	return _name;
}

void ClapTrap::setName(std::string name)
{
	_name = name;
}

unsigned int ClapTrap::getHitPoint(void)
{
	return _hitP;
}

void ClapTrap::setHitPoint(unsigned int hitP)
{
	_hitP = hitP;
}

unsigned int ClapTrap::getEnergyPoint(void)
{
	return _energyP;
}

void ClapTrap::setEnerergyPoint(unsigned int energyP)
{
	_energyP = energyP;
}

unsigned int ClapTrap::getAttackDamage(void)
{
	return _attackP;
}

void ClapTrap::setAttackDamage(unsigned int attackP)
{
	_attackP = attackP;
}
