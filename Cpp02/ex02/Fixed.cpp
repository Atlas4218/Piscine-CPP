/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:28:32 by rastie            #+#    #+#             */
/*   Updated: 2024/01/16 19:14:02 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <math.h>

Fixed::Fixed(void): _value(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::Fixed(const int n): _value(n << this->_nbits)
{
    //std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n): _value(roundf(n * (1 << this->_nbits)))
{
    //std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    this->_value = rhs.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return (this->_value);
}

void Fixed::setRawBits(int const var)
{
    this->_value = var;
}

int Fixed::toInt(void) const
{
    return this->_value >> _nbits;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>( this->_value ) / ( 1 << this->_nbits );
}

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
    o << i.toFloat();
    return (o);
}

bool Fixed::operator<(Fixed const &rhs)
{
    return (this->_value < rhs.getRawBits());
}

bool Fixed::operator>(Fixed const &rhs)
{
    return (this->_value > rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const &rhs)
{
    return (this->_value <= rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const &rhs)
{
    return (this->_value >= rhs.getRawBits());
}

bool Fixed::operator==(Fixed const &rhs)
{
    return (this->_value == rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const &rhs)
{
    return (this->_value != rhs.getRawBits());
}

Fixed Fixed::operator+(Fixed const &rhs)
{
    return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(Fixed const &rhs)
{
    return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(Fixed const &rhs)
{
    return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(Fixed const &rhs)
{
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    this->_value++;
    return tmp;
}

Fixed Fixed::operator++(void)
{
    ++this->_value;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    this->_value--;
    return tmp;
}

Fixed Fixed::operator--(void)
{
    --this->_value;
    return *this;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}