/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:22:25 by rastie            #+#    #+#             */
/*   Updated: 2024/01/20 14:50:13 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog: public Animal
{
public:
	Dog(void);
	Dog(const Dog & dog);
	Dog & operator=(const Dog & rhs);
	virtual ~Dog(void);

	virtual void makeSound(void) const;
};
#endif
