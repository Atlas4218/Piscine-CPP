/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:28:32 by rastie            #+#    #+#             */
/*   Updated: 2024/01/07 17:07:39 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed): _value(fixed._value)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int n): _value()
{
}

Fixed::Fixed(const float n)
{
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
   this->_value = rhs.getRawBits();
   return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

void Fixed::setRawBits(int const var)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = var;
}

int Fixed::toInt(void) const
{
    return 0;
}

float Fixed::toFloat(void) const
{
    return 0.0f;
}

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
    // TODO: insert return statement here
}
