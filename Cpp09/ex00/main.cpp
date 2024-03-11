/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:38:03 by rastie            #+#    #+#             */
/*   Updated: 2024/03/11 17:47:18 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <list>

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;
    try
    {
        BitcoinExchange btc;
    }
    catch(const std::exception& e)
    {
        std::cerr << "_fileDatabase init: " << e.what() << '\n';
    }
    try
    {
        //btc.exchange(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exchange: " << e.what() << '\n';
    }
    
}