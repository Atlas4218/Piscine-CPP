/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:48:13 by rastie            #+#    #+#             */
/*   Updated: 2024/01/21 16:38:34 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog & dog): AAnimal(dog)
{
	_brain = new Brain(*dog._brain);
	std::cout << "Dog Copy constructor called" << std::endl;
}

Dog & Dog::operator=(const Dog & dog)
{
	if (_brain)
		delete (_brain);
	_brain = new Brain(*dog._brain);
	_type = dog.getType();
	std::cout << "Dog Copy assignment constructor called" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof Woof" << std::endl;
}
