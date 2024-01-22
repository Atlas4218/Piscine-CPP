/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:16:06 by rastie            #+#    #+#             */
/*   Updated: 2024/01/22 17:05:27 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
#include "AMateria.hpp"

class Ice: public AMateria
{
	private:

	public:
		Ice(void);
		Ice(Ice const & ice);
		virtual ~Ice(void);
		Ice & operator=(Ice const & ice);

		virtual Ice* clone(void) const;
		virtual void use(ICharacter& target);

};
#endif
