/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:01:06 by rastie            #+#    #+#             */
/*   Updated: 2024/02/05 18:09:25 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string litteral)
{
	std::cout << "char: \n";
	if (litteral.find("inf") || litteral.find("nan"))
		std::cout << "impossible\n";
	else 
	{
		try 
		{
			if (std::stoi(litteral) < 32 || std::stoi(litteral) > 126)
				std::cout << "Non diplayable\n";
			else
				sdt::cout << char(std::stoi(litteral)) << std::endl;		
		}
		catch (std::exception e)
			std::cout << e.what() << std::endl;
	}

	std::cout << "int: \n";
	if (litteral.find("inf") || litteral.find("nan"))
		std::cout << "impossible\n";
	else
	{
		try
			sdt::cout << std::stoi(litteral) << std::endl;
		catch(std::exception e)
			std::cout << e.what() << std::endl;
	}

	std::cout << "float: \n";
	if (litteral.find("inf"))
	{
		if (litteral == "-inf" || litteral == "-inff")
			std::cout << "-inff\n";
		if (litteral == "+inf" || litteral == "+inff")
			std::cout << "+inff\n";
	}
	else if (!litteral.compare(0, 3, "nan"))
		std::cout << "nanf\n";
	else
	{
		try
			std::cout << std::stof(litteral) << std::endl;
		catch(std::exception e)
			std::cout << e.what() << std::endl;
	}

	std::cout << "double: \n";
	if (litteral.find("inf"))
	{
		if (litteral == "-inf" || litteral == "-inff")
			std::cout << "-inf\n";
		if (litteral == "+inf" || litteral == "+inff")
			std::cout << "+inf\n";
	}
	else if (!litteral.compare(0, 3, "nan"))
		std::cout << "nan\n";
	else
	{
		try
			std::cout << std::stod(litteral) << std::endl;
		catch(std::exception e)
			std::cout << e.what() << std::endl;
	}


}
