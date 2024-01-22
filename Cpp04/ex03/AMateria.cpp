/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:03:13 by rastie            #+#    #+#             */
/*   Updated: 2024/01/22 16:25:41 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"


AMateria::AMateria(void)
{
}


AMateria::AMateria(AMateria const & amateria)
{
	*this = amateria;
}


AMateria::~AMateria(void)
{
}


AMateria & AMateria::operator=(AMateria const & amateria)
{
	_type = amateria._type;
	return (*this);
}


AMateria::AMateria(std::string const & type)
{
	_type = type;
}


std::string const & AMateria::getType(void) const
{
	return (_type);
}


void AMateria::use(ICharacter& target)
{
	std::cout << " use some materia on " << target.getName();
}
