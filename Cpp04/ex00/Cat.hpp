/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:22:25 by rastie            #+#    #+#             */
/*   Updated: 2024/01/20 14:50:13 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat: public Animal
{
public:
	Cat(void);
	Cat(const Cat & dog);
	Cat & operator=(const Cat & rhs);
	virtual ~Cat(void);

	virtual void makeSound(void) const;
};
#endif
