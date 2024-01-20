/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:01:18 by rastie            #+#    #+#             */
/*   Updated: 2024/01/20 15:07:00 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <string>
# include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;

	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal & animal);
		~WrongAnimal(void);
		WrongAnimal & operator=(const WrongAnimal & rhs);

		std::string getType(void) const;
		void setType(std::string type);

		void makeSound(void) const;


};
#endif
