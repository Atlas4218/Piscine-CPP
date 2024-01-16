/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:33:21 by rastie            #+#    #+#             */
/*   Updated: 2024/01/16 19:09:18 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
private:
    int _value;
    static const int _nbits = 8;
public:
    Fixed(void);
    Fixed(const Fixed &fixed);
    Fixed(const int n);
    Fixed(const float n);
    Fixed & operator=(Fixed const & rhs);

    bool operator<(Fixed const & rhs);
    bool operator>(Fixed const & rhs);
    bool operator<=(Fixed const & rhs);
    bool operator>=(Fixed const & rhs);
    bool operator==(Fixed const & rhs);
    bool operator!=(Fixed const & rhs);

    Fixed operator+(Fixed const & rhs);
    Fixed operator-(Fixed const & rhs);
    Fixed operator*(Fixed const & rhs);
    Fixed operator/(Fixed const & rhs);

    Fixed operator++(int);
    Fixed operator++(void);
    Fixed operator--(int);
    Fixed operator--(void);

    static Fixed & min(Fixed &a, Fixed &b);
    static const Fixed & min(const Fixed &a, const Fixed &b);
    static Fixed & max(Fixed &a, Fixed &b);
    static const Fixed & max(const Fixed &a, const Fixed &b);

    ~Fixed();

    void setRawBits(int const var);
    int getRawBits(void) const;
    int toInt(void) const;
    float toFloat(void) const;
};
std::ostream & operator<<(std::ostream & o, Fixed const & i);
