/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:48:11 by rastie            #+#    #+#             */
/*   Updated: 2024/01/20 16:55:10 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat & dog)
{
	*this = dog;
	std::cout << "Cat Copy constructor called" << std::endl;
}

Cat & Cat::operator=(const Cat & cat)
{
	if (_brain)
		delete _brain;
	_brain = new Brain(*cat._brain);
	_type = cat.getType();
	std::cout << "Cat Copy assignment constructor called" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow Meow" << std::endl;
}
