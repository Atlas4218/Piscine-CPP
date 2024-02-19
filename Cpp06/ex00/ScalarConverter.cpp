/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:01:06 by rastie            #+#    #+#             */
/*   Updated: 2024/02/19 16:57:15 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void toChar(std::string str)
{
	long i;
	char *p_end = 0;
	std::cout << "char: ";
	if (str.size() <= 1 && !isdigit(str.at(0)))
		std::cout << "\'" << str << "\'" << std::endl;
	else 
	{
		i = std::strtol(str.c_str(), &p_end, 10);
		if (errno == ERANGE || i < 0 || i > 256 || p_end == str.c_str())
			std::cout << "impossible convertion\n";
		else if (i < 32 || i > 126)
			std::cout << "non displayable\n";
		else
			std::cout << "\'" << char(i) << "\'" << std::endl;
	}
	errno = 0;
}

void toInt(std::string str)
{
	long i;
	char *p_end = 0;
	std::cout << "int: ";

	if (str.size() <= 1 && isdigit(str.at(0)))
		std::cout << str << std::endl;
	else 
	{
		if (str.size() == 1)
			i = int(str.at(0));
		else
			i = std::strtol(str.c_str(), &p_end, 10);
		if (errno == ERANGE || i < INT_MIN || i > INT_MAX || p_end == str.c_str())
			std::cout << "impossible convertion\n";
		else
			std::cout << i << std::endl;
	}
	errno = 0;
}

void toFloatDouble(std::string str)
{
	char *end = 0;
	double result;
	std::cout << "float: ";
	if (str.size() <= 1 && !isdigit(str.at(0)))
		result = int(str.at(0));
	else
		result = std::strtod(str.c_str(), &end);
	if (errno || end == str.c_str())
		std::cout << "impossible convertion\n";
	else
	{
		std::cout << static_cast<float>(result);
		if (result - static_cast<int>(result) == 0)
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}

	std::cout << "double: ";
	if (errno || end == str.c_str())
		std::cout << "impossible convertion\n";
	else
	{
		std::cout << result;
		if (result - static_cast<int>(result) == 0)
			std::cout << ".0" << std::endl;
	}
}
void ScalarConverter::convert(std::string litteral)
{
	toChar(litteral);
	toInt(litteral);
	toFloatDouble(litteral);
}
