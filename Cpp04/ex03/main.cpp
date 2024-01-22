/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:53:15 by rastie            #+#    #+#             */
/*   Updated: 2024/01/22 15:53:15 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	
	Character* cMe = new Character("me");

	MateriaSource* mSrc = new MateriaSource();
	mSrc->learnMateria(new Ice());
	mSrc->learnMateria(new Cure());
	mSrc->learnMateria(new Ice());
	mSrc->learnMateria(new Cure());
	
	tmp = mSrc->createMateria("fireball");
	tmp = mSrc->createMateria("ice");
	cMe->equip(tmp);
	cMe->unequip(0);
	
	Character meBis = Character(*cMe);

	delete tmp;
	delete cMe;
	delete mSrc;
	return 0;
}
