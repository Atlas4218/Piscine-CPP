/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:11:23 by rastie            #+#    #+#             */
/*   Updated: 2024/01/22 11:49:00 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	//non autorises (AAnimal est une classe abstraite)
	//AAnimal meta = AAnimal();
	//const AAnimal* metaptr = new AAnimal();
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	std::cout << std::endl;
	Dog* dog = new Dog();
	Dog dogCopy(*dog);
	std::cout << std::endl;
	delete j;
	delete i;
	delete dog;

	std::cout << std::endl;

	AAnimal* animaux[10];
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
