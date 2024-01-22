/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:48:12 by rastie            #+#    #+#             */
/*   Updated: 2024/01/20 15:06:57 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal & animal)
{
	*this = animal;
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal & animal)
{
	_type = animal.getType();
	std::cout << "WrongAnimal Copy assignment constructor called" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (_type);
}

void WrongAnimal::setType(std::string type)
{
	_type = type;
}

void WrongAnimal::makeSound(void) const 
{
	std::cout << "Wrong Animal sound" << std::endl;
}
