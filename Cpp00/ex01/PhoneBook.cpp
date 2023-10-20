/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:43:10 by rastie            #+#    #+#             */
/*   Updated: 2023/10/16 19:17:08 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream> 
#include <iomanip> 
#include <string>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "PhoneBook constructor called" << std::endl;
	for(int i = 0; i < 8; i++)
	{
		this->list[i] = Contact();
	}
	this->index_older = 0;
}
PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook destructor called" << std::endl;
}

void	PhoneBook::add_contact(std::string fname, std::string lname, 
		std::string nname, std::string num, std::string secret)
{
	this->list[index_older % 8].setFirstName(fname);
	this->list[index_older % 8].setLastName(lname);
	this->list[index_older % 8].setNickname(nname);
	this->list[index_older % 8].setPhoneNumber(num);
	this->list[index_older % 8].setSecret(secret);
	this->index_older++;
}

void	PhoneBook::print_content()
{
	for (int i = 0; i < 8; i++)
	{
		Contact contact = this->list[i];

		std::string fname = "|" + contact.getFirstName();
		fname.resize(10, ' ');
		if (fname[10] != ' ')
			fname.replace(fname.begin(), fname.end(), 1, '.');
		std::string lname = "|" + contact.getFirstName();
		lname.resize(10, ' ');
		if (lname[10] != ' ')
			lname.replace(lname.begin(), lname.end(), 1, '.');
		std::string nname = "|" + contact.getNickname();
		nname.resize(10, ' ');
		if (nname[10] != ' ')
			nname.replace(nname.begin(), nname.end(), 1, '.');
		std::string num = "|" + contact.getPhoneNumber();
		num.resize(10, ' ');
		if (num[10] != ' ')
			num.replace(fname.begin(), fname.end(), 1, '.');
		std::cout << std::left << std::setfill(' ') << std::setw(10);
		std::cout << i << fname << lname << num << std::endl;
	}
}

void	PhoneBook::print_contact(int index)
{
	std::cout << this->list[index].getFirstName() << std::endl;
	std::cout << this->list[index].getLastName() << std::endl;
	std::cout << this->list[index].getNickname() << std::endl;
	std::cout << this->list[index].getPhoneNumber() << std::endl;
	std::cout << this->list[index].getSecret() << std::endl;
}

int	main()
{
	PhoneBook phonebook;
