/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:43:10 by rastie            #+#    #+#             */
/*   Updated: 2024/01/05 18:37:53 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		std::cout << "First name :";
		take_input(fname);
	}
	while (!lname[0])
	{
		std::cout << "Last name :";
		take_input(lname);
	}
	while (!nname[0])
	{
		std::cout << "Nickname :";
		take_input(nname);
	}
	while (!number[0] || !num_valid(number))
	{
		std::cout << "Phone number :";
		take_input(number);
	}
	while (!secret[0])
	{
		std::cout << "Secret :";
		take_input(secret);
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
	std::cout << "     Index|    Prenom|       Nom| Phone Num" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::string fname = this->list[i].getFirstName();
		if (fname.length() > 10)
		{
			fname.resize(10);
			fname.replace(9, 1, ".");
		}
		std::string lname = this->list[i].getLastName();
		if (lname.length() > 10)
		{
			lname.resize(10);
			lname.replace(9, 1, ".");
		}
		std::string num = this->list[i].getPhoneNumber();
		std::cout.setf(std::ios_base::right);
		std::cout << std::setfill(' ');
		std::cout << std::setw(10) << i + 1 << "|"
				  << std::setw(10) << fname << "|"
		  		  << std::setw(10) << lname << "|"
		   		  << std::setw(10) << num << std::endl;
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
		take_input(entry);
		std::istringstream(entry) >> index;
	}
if (this->list[index - 1].getFirstName() == "")
		std::cout << "Empty contact" << std::endl;
	else
		this->print_contact(index - 1);
}

int	main()
{
	PhoneBook	 phonebook;
	std::string	cmd;
	

	while (1)
	{
		cmd = "";
		std::cout << "CMDS:\nADD, SEARCH, EXIT" << std::endl;
		take_input(cmd);
		const char *str = cmd.c_str();
		(void) str;
		if (!cmd.compare("EXIT"))
			break ;
		if (!cmd.compare("ADD"))
			phonebook.add_contact();
		if (!cmd.compare("SEARCH"))
			phonebook.search();
	}
	return (0);
}

