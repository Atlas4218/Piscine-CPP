/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:35:40 by rastie            #+#    #+#             */
/*   Updated: 2024/02/20 17:42:26 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *generate(void)
{
    int i = rand() % 3;
    if (!i)
        return (new A());
    else if (i == 1)
        return (new B());
    return (new C());
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "class is type A" << std::endl;
    if (dynamic_cast<B*>(p))
        std::cout << "class is type B" << std::endl;
    if (dynamic_cast<C*>(p))
        std::cout << "class is type C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        std::cout << "class is type A" << std::endl;
        static_cast<void>(a);
    }
    catch(std::exception &e){}
    try
    {
        B &b = dynamic_cast<B&>(p);
        std::cout << "class is type B" << std::endl;
        static_cast<void>(b);
    }
    catch(std::exception &e){}
    try
    {
        C &c = dynamic_cast<C&>(p);
        std::cout << "class is type C" << std::endl;
        static_cast<void>(c);
    }
    catch(std::exception){}
}

Base::~Base()
{
}
