/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:33:21 by rastie            #+#    #+#             */
/*   Updated: 2024/01/03 22:08:13 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
private:
    int _value;
    const int _nbits;
public:
    Fixed(void);
    Fixed(const Fixed &fixed);
    Fixed & operator=(Fixed const & rhs);
    ~Fixed();

    void setRawBits(int const var);
    int getRawBits(void) const;
};

Fixed::Fixed(void): _value(0), _nbits(8)
{
    //std::cout << "Fixed default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed): _value(fixed._value), _nbits(8)
{
    //std::cout << "Fixed copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
   this->_value = rhs.getRawBits();
   return (*this);
}

Fixed::~Fixed()
{
    //std::cout << "Fixed destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return (this->_value);
}

void Fixed::setRawBits(int const var)
{
    this->_value = var;
}
