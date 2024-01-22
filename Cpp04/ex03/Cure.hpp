/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:16:04 by rastie            #+#    #+#             */
/*   Updated: 2024/01/22 16:10:06 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
#include "AMateria.hpp"

class Cure: public AMateria
{
	private:

	public:
		Cure(void);
		Cure(Cure const & cure);
		virtual ~Cure(void);
		Cure & operator=(Cure const & cure);

		virtual Cure* clone(void) const;
		virtual void use(ICharacter& target);

};
#endif
