/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:53:23 by ael-khni          #+#    #+#             */
/*   Updated: 2024/02/27 19:14:50 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main( int ac, char ** av )
{
    if ( ac != 2 )
        return 1;

    int                 arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::vector< int >      vect( arr, arr + sizeof( arr ) / sizeof( int ) );
    std::list< int >        list( arr, arr + sizeof( arr ) / sizeof( int ) );

    easyfind( vect, std::atoi( av[1] ));
    easyfind( list, std::atoi( av[1] ));

    return EXIT_SUCCESS;
}