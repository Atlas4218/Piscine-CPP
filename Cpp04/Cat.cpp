/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:48:11 by rastie            #+#    #+#             */
/*   Updated: 2024/01/19 18:59:04 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	_type = "Cat";
	std::cout << "Cat Default constructor called" << std::endl;
}


Cat::Cat(const Cat & dog)
{
	*this = dog;
	std::cout << "Cat Copy constructor called" << std::endl;
}


Cat & Cat::operator=(const Cat & dog)
{
	_type = dog.getType();
	std::cout << "Cat Copy assignment constructor called" << std::endl;
}


Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}


std::string Cat::getType(void)
{
	return (_type);
}


void Cat::setType(std::string type)
{
	_type = type;
}


void Cat::makeSound(void)
{
	std::cout << "Meow Meow" << std::endl;
}
