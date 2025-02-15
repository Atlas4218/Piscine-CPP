/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:10:24 by rastie            #+#    #+#             */
/*   Updated: 2024/01/03 13:03:47 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type)
{
    std::cout << "Weapon constructor called" << std::endl;
}

Weapon::~Weapon()
{
        std::cout << "Weapon destructor called" << std::endl;
}

std::string &Weapon::getType(void)
{
    return (this->_type);
}

void Weapon::setType(std::string type)
{
    this->_type = type;
}