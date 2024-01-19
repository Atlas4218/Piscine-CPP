/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:22:25 by rastie            #+#    #+#             */
/*   Updated: 2024/01/19 18:48:18 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Dog: public Animal
{
public:
	Dog(void);
	Dog(const Dog & dog);
	Dog & operator=(const Dog & rhs);
	~Dog(void);

	void makeSound(void);
};
