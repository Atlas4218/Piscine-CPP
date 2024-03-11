/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:38:03 by rastie            #+#    #+#             */
/*   Updated: 2024/03/11 21:35:51 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <list>

int main(int ac, char **av)
{
    BitcoinExchange btc;
    if (ac != 2)
        return 1;
    try
    {
        btc.initDataBase();
    }
    catch(const std::exception& e)
    {
        std::cerr << "_fileDatabase init: " << e.what() << '\n';
        return (1);
    }
    try
    {
        btc.exchange(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (1);
    }
    (void)av;
    return (0);
}