/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:18:18 by rastie            #+#    #+#             */
/*   Updated: 2024/01/22 17:04:59 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria* _materias[4];

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource & source);
		virtual ~MateriaSource(void);
		MateriaSource & operator=(const MateriaSource & rhs);

		virtual	void learnMateria(AMateria* materia);
		virtual AMateria *createMateria(const std::string & type);

};
#endif
