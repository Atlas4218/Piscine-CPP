/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:48:12 by rastie            #+#    #+#             */
/*   Updated: 2024/01/19 18:48:18 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << "AAnimal Default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal & animal)
{
	*this = animal;
	std::cout << "AAnimal Copy constructor called" << std::endl;
}

AAnimal & AAnimal::operator=(const AAnimal & animal)
{
	_type = animal.getType();
	std::cout << "AAnimal Copy assignment constructor called" << std::endl;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType(void) const
{
	return (_type);
}

void AAnimal::setType(std::string type)
{
	_type = type;
}
