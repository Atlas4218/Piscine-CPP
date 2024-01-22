/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:48:11 by rastie            #+#    #+#             */
/*   Updated: 2024/01/20 15:07:39 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	_type = "WrongCat";
	std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat & dog)
{
	*this = dog;
	std::cout << "WrongCat Copy constructor called" << std::endl;
}

WrongCat & WrongCat::operator=(const WrongCat & dog)
{
	_type = dog.getType();
	std::cout << "WrongCat Copy assignment constructor called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "Woem Woem" << std::endl;
}
