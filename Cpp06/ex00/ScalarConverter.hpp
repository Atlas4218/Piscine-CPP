/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:01:04 by rastie            #+#    #+#             */
/*   Updated: 2024/02/14 18:44:19 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>
# include <iostream>
# include <climits>
# include <cerrno>
# include <cstdlib>

class ScalarConverter
{
private:


public:
	static void convert(std::string litteral);
	class OverflowException : public std::exception
    {
        public:
            virtual const char* what() const throw() {return "Value out of bound";}
    };
};
#endif
