/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:22:25 by rastie            #+#    #+#             */
/*   Updated: 2024/01/19 18:47:30 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Cat: public Animal
{
public:
	Cat(void);
	Cat(const Cat & dog);
	Cat & operator=(const Cat & rhs);
	~Cat(void);

	void makeSound(void);
};
