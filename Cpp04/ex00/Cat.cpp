/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:48:11 by rastie            #+#    #+#             */
/*   Updated: 2024/01/20 15:06:19 by rastie           ###   ########.fr       */
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
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}
