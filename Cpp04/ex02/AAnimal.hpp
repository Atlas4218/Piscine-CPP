/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:01:18 by rastie            #+#    #+#             */
/*   Updated: 2024/01/21 14:16:24 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include <string>
# include <iostream>

class AAnimal
{
	protected:
		std::string _type;

	public:
		AAnimal(void);
		AAnimal(const AAnimal & animal);
		virtual ~AAnimal(void);
		AAnimal & operator=(const AAnimal & rhs);

		std::string getType(void) const;
		void setType(std::string type);

		virtual void makeSound(void) const = 0;


};
#endif
