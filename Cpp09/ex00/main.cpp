/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:38:03 by rastie            #+#    #+#             */
/*   Updated: 2024/03/08 17:59:56 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <list>

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;
    BitcoinExchange btc;
    try
    {
        btc.initDataBase(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << "_fileDatabase init: " << e.what() << '\n';
    }
}