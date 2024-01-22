/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:03:13 by rastie            #+#    #+#             */
/*   Updated: 2024/01/22 16:42:27 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"


Cure::Cure(void): AMateria("cure")
{
	//std::cout << "Default Cure constructor called" << std::endl;
}


Cure::Cure(Cure const & cure)
{
	*this = cure;
}


Cure::~Cure(void)
{
	//std::cout << "Cure Destructor called" << std::endl;
}


Cure & Cure::operator=(Cure const & cure)
{
	_type = cure._type;
	return (*this);
}


void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}


Cure* Cure::clone(void) const
{
	return (new Cure());
}
