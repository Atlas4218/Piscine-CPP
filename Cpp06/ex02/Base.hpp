/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:58:55 by rastie            #+#    #+#             */
/*   Updated: 2024/02/20 17:42:35 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP
# include <cmath>
# include <ctime>
# include <iostream>
class Base
{
private:
    /* data */
public:
    virtual ~Base();
};
class A: public Base{};
class B: public Base{};
class C: public Base{};

Base *generate(void);

void identify(Base *p);
void identify(Base &p);

#endif