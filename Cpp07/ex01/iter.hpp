/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:10:15 by rastie            #+#    #+#             */
/*   Updated: 2024/02/27 18:10:16 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

template <typename A>
void iter(A *array, int lenght, void (*function)(A const &element))
{
    for (int i = 0; i < lenght; i++)
        function(array[i]);
    
}