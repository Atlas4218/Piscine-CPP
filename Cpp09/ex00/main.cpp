/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:38:03 by rastie            #+#    #+#             */
/*   Updated: 2024/03/12 16:08:35 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    BitcoinExchange btc;
    if (ac != 2)
    {
        std::cerr << "Usage: ./btc <filename>" << std::endl;
        return 1;
    }
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
        std::cerr << "Exchange: " << e.what() << '\n';
        return (1);
    }
    (void)av;
    return (0);
}