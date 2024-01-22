/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:03:14 by rastie            #+#    #+#             */
/*   Updated: 2024/01/22 17:05:35 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include "ICharacter.hpp"
# include <iostream>
# include <string>

class ICharacter;

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria(void);
		AMateria(AMateria const & amateria);
		virtual ~AMateria(void);
		AMateria & operator=(AMateria const & amateria);

		AMateria(std::string const & type);

		std::string const & getType(void) const;

		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target);
};
#endif
