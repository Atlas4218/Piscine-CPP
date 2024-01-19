/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:48:12 by rastie            #+#    #+#             */
/*   Updated: 2024/01/19 18:48:18 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


Animal::Animal(void)
{
	std::cout << "Animal Default constructor called" << std::endl;
}


Animal::Animal(const Animal & animal)
{
	*this = animal;
	std::cout << "Animal Copy constructor called" << std::endl;
}


Animal & Animal::operator=(const Animal & animal)
{
	_type = animal.getType();
	std::cout << "Animal Copy assignment constructor called" << std::endl;
}


Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}


std::string Animal::getType(void)
{
	return (_type);
}


void Animal::setType(std::string type)
{
	_type = type;
}


void Animal::makeSound(void)
{
	std::cout << "Undefinable animal sound" << std::endl;
}
