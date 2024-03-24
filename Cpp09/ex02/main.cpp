/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:57:15 by rastie            #+#    #+#             */
/*   Updated: 2024/03/24 23:58:28 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2){std::cout << "Error\n"; return (1);}
    
    try
    {
        PmergeMe pmerge(++av);
        pmerge.sort();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}