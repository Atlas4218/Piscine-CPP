/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:33:21 by rastie            #+#    #+#             */
/*   Updated: 2024/01/07 17:06:37 by rastie           ###   ########.fr       */
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
    Fixed & operator=(Fixed const & rhs);
    ~Fixed();

    void setRawBits(int const var);
    int getRawBits(void) const;
};
