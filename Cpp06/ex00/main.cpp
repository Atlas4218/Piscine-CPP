/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:17:30 by rastie            #+#    #+#             */
/*   Updated: 2024/02/14 15:34:21 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
        return (0);
    
    for (int i = 1; i < ac; i++)
    {
        std::cout << "entry: " << av[i] << std::endl;
        ScalarConverter::convert(av[i]);
        std::cout << std::endl;
    }
    return (0);
}