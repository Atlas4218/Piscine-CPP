/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:43:10 by rastie            #+#    #+#             */
/*   Updated: 2023/12/31 13:59:08 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <iomanip> 
#include <string>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "PhoneBook constructor called" << std::endl;
}
PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook destructor called" << std::endl;
}

int	num_valid(std::string num)
{
	if (num.length() != 10)
		return (0);
	for (size_t i = 0; i < num.length(); i++)
		if (num.at(i) < '0' || num.at(i) > '9')
			return (0);
	return (1);
}
void	PhoneBook::add_contact(void)
{
	std::string	fname;
	std::string	lname;
	std::string	nname;
	std::string	number;
	std::string	secret;

	while (!fname[0])
	{
		std::cout << "First name :" << std::endl;
		std::getline(std::cin, fname);
	}
	while (!lname[0])
	{
		std::cout << "Last name :";
		std::getline(std::cin, lname);
	}
	while (!nname[0])
	{
		std::cout << "Nickname :";
		std::getline(std::cin, nname);
	}
	while (!number[0] && !num_valid(number))
	{
		std::cout << "Phone number :";
		std::getline(std::cin, number);
	}
	while (!secret[0])
	{
		std::cout << "Secret :";
		std::getline(std::cin, secret);
	}

	this->list[this->index_older % 8].setFirstName(fname);
	this->list[this->index_older % 8].setLastName(lname);
	this->list[this->index_older % 8].setNickname(nname);
	this->list[this->index_older % 8].setPhoneNumber(number);
	this->list[this->index_older % 8].setSecret(secret);
	this->index_older++;
}

void	PhoneBook::print_content(void)
{
	for (int i = 0; i < 8; i++)
	{
		std::string fname = "|" + this->list[i].getFirstName();
		fname.resize(10, ' ');
		if (fname[9] && fname[9] != ' ')
			fname.replace(9, 1, 1, '.');
		std::string lname = "|" + this->list[i].getFirstName();
		lname.resize(10, ' ');
		if (lname[9] && lname[9] != ' ')
			lname.replace(9, 1, 1, '.');
		std::string nname = "|" + this->list[i].getNickname();
		nname.resize(10, ' ');
		if (nname[9] && nname[9] != ' ')
			nname.replace(9, 1, 1, '.');
		std::string num = "|" + this->list[i].getPhoneNumber();
		num.resize(10, ' ');
		if (num[9] && num[9] != ' ')
			num.replace(9, 1, 1, '.');
		std::cout << i + 1;
		std::cout << std::left << std::setfill(' ') << std::setw(10);
		std::cout << fname << lname << num << std::endl;
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
void	PhoneBook::search(void)
{
	int	index;
	std::string	entry;

	index = -1;
	this->print_content();
	while (index < 1 || index > 8)
	{
		std::cout << "Enter index :";
		std::cin >> entry;
		std::istringstream ( entry ) >> index;
	}
	this->print_contact(index - 1);
}

int	main()
{
	PhoneBook	 phonebook;
	std::string	cmd;

	while (1)
	{
		std::cout << "CMDS:\nADD, SEARCH, EXIT" << std::endl;
		std::getline(std::cin, cmd);
		if (!cmd.compare("EXIT"))
			break ;
		if (!cmd.compare("ADD"))
			phonebook.add_contact();
		if (!cmd.compare("SEARCH"))
			phonebook.search();
	}
}

