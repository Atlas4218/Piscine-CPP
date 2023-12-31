/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:14:51 by rastie            #+#    #+#             */
/*   Updated: 2023/12/31 13:58:53 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Contact.hpp"

Contact::Contact()
{
	std::cout << "Contact constructor called" << std::endl;
}
Contact::~Contact()
{
	std::cout << "Contact destructor called" << std::endl;
}

std::string Contact::getFirstName()
{
	return (this->first_name);
}
std::string Contact::getLastName()
{
	return (this->last_name);
}
std::string Contact::getNickname()
{
	return (this->last_name);
}
std::string Contact::getPhoneNumber()
{
	return (this->phone_number);
}
std::string Contact::getSecret()
{
	return (this->secret);
}

void Contact::setFirstName(std::string first_name)
{
	this->first_name = first_name;
}
void Contact::setLastName(std::string last_name)
{
	this->last_name = last_name;
}
void Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;
}
void Contact::setPhoneNumber(std::string phone_number)
{
	this->phone_number = phone_number;
}
void Contact::setSecret(std::string secret)
{
	this->secret = secret;
}
