/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:11:23 by rastie            #+#    #+#             */
/*   Updated: 2024/01/20 21:48:09 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	Dog* dog = new Dog();
	Dog dogCopy(*dog);
	std::cout << std::endl;
	delete j;//should not create a leak
	delete i;
	delete dog;

	std::cout << std::endl;

	Animal* animaux[10];
	for (int i = 0; i < 4; i++)
	{
		if (i % 2)
			animaux[i] = new Dog();
		else
			animaux[i] = new Cat();
	}
	
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
		delete animaux[i];
	return 0;
}
