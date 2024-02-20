/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:17:30 by rastie            #+#    #+#             */
/*   Updated: 2024/02/20 17:42:18 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
    srand(std::time(0));

    Base*   a = generate();
    Base*   b = generate();
    Base*   c = generate();
    Base*   d = generate();
    Base*   e = generate();
    Base*   f = generate();
    Base*   g = generate();
    Base*   h = generate();

    std::cout << "/* **************************************** */" << std::endl;

    std::cout << "a* = "; identify( a );
    std::cout << "a& = "; identify( *a ); std::cout << std::endl;

    std::cout << "b* = "; identify( b );
    std::cout << "b& = "; identify( *b ); std::cout << std::endl;

    std::cout << "c* = "; identify( c );
    std::cout << "c& = "; identify( *c ); std::cout << std::endl;

    std::cout << "d* = "; identify( d );
    std::cout << "d& = "; identify( *d ); std::cout << std::endl;

    std::cout << "e* = "; identify( e );
    std::cout << "e& = "; identify( *e ); std::cout << std::endl;

    std::cout << "f* = "; identify( f );
    std::cout << "f& = "; identify( *f ); std::cout << std::endl;

    std::cout << "g* = "; identify( g );
    std::cout << "g& = "; identify( *g ); std::cout << std::endl;

    std::cout << "h* = "; identify( h );
    std::cout << "h& = "; identify( *h ); std::cout << std::endl;

    std::cout << "/* ***************************************** */" << std::endl;


    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
    delete f;
    delete g;
    delete h;

    return (0);
}