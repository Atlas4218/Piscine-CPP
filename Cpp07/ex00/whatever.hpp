/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:55:15 by rastie            #+#    #+#             */
/*   Updated: 2024/02/27 17:48:30 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>
#include <string>
template<typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
T &min(T &a, T &b){return (a < b? a : b);}
template<typename T>
T &max(T &a, T &b){return (a > b? a : b);}
#endif