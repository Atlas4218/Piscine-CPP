/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:33:21 by rastie            #+#    #+#             */
/*   Updated: 2024/01/04 16:18:03 by rastie           ###   ########.fr       */
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
    ~Fixed();

    void setRawBits(int const var);
    int getRawBits(void) const;
    int toInt(void) const;
    float toFloat(void) const;
};
std::ostream & operator<<(std::ostream & o, Fixed const & i);
