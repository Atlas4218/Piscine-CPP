/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:11:23 by rastie            #+#    #+#             */
/*   Updated: 2024/01/20 15:09:01 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	std::cout << std::endl;
	
	const WrongCat* wCat = new WrongCat();
	const WrongAnimal* wMeta = new WrongCat();
	std::cout << wCat->getType() << " " << std::endl;
	std::cout << wMeta->getType() << " " << std::endl;
	wCat->makeSound(); //will output the cat sound!
	wMeta->makeSound();

	delete meta;
	delete j;
	delete i;
	delete wCat;
	delete wMeta;
	return 0;
}
