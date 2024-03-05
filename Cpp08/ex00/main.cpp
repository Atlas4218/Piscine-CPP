/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:53:23 by ael-khni          #+#    #+#             */
/*   Updated: 2024/03/05 17:59:13 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main( int ac, char ** av )
{
    if ( ac != 2 )
        return 1;

    int                 arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::vector< int >      vect( arr, arr + sizeof( arr ) / sizeof( int ) );

    try
    {
        if (easyfind( vect, std::atoi( av[1] )) != vect.end())
            std::cout << "Found!\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
       

    return EXIT_SUCCESS;
}