/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:03:13 by rastie            #+#    #+#             */
/*   Updated: 2024/01/22 16:42:30 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"


Ice::Ice(void): AMateria("ice")
{
	//std::cout << "Default Ice constructor called" << std::endl;
}


Ice::Ice(Ice const & ice)
{
	*this = ice;
}


Ice::~Ice(void)
{
	//std::cout << "Ice Destructor called" << std::endl;
}


Ice & Ice::operator=(Ice const & ice)
{
	_type = ice._type;
	return (*this);
}


void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}


Ice* Ice::clone(void) const
{
	return (new Ice());
}
