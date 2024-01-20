/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:01:18 by rastie            #+#    #+#             */
/*   Updated: 2024/01/20 14:50:13 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include <iostream>

class Animal
{
	protected:
		std::string _type;

	public:
		Animal(void);
		Animal(const Animal & animal);
		virtual ~Animal(void);
		Animal & operator=(const Animal & rhs);

		std::string getType(void) const;
		void setType(std::string type);

		virtual void makeSound(void) const;


};
#endif
