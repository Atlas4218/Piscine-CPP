/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:10:24 by rastie            #+#    #+#             */
/*   Updated: 2023/12/31 14:18:26 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string str): type(str)
{
    std::cout << "Weapon constructor called" << std::endl;
}

Weapon::~Weapon()
{
        std::cout << "Weapon destructor called" << std::endl;
}

std::string &Weapon::getType(void)
{
    return (this->type);
}

void Weapon::setType(std::string str)
{
    this->type = str;
}