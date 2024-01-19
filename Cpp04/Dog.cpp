/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:48:13 by rastie            #+#    #+#             */
/*   Updated: 2024/01/19 18:49:39 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	_type = "Dog";
	std::cout << "Dog Default constructor called" << std::endl;
}


Dog::Dog(const Dog & dog)
{
	*this = dog;
	std::cout << "Dog Copy constructor called" << std::endl;
}


Dog & Dog::operator=(const Dog & dog)
{
	_type = dog.getType();
	std::cout << "Dog Copy assignment constructor called" << std::endl;
}


Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}


std::string Dog::getType(void)
{
	return (_type);
}


void Dog::setType(std::string type)
{
	_type = type;
}


void Dog::makeSound(void)
{
	std::cout << "Woof Woof" << std::endl;
}
