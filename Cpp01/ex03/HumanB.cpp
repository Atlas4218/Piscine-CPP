/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:09:00 by rastie            #+#    #+#             */
/*   Updated: 2023/12/31 14:44:40 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
    std::cout << "HumanB " << this->_name << " constructor called" << std::endl;
}

HumanB::~HumanB()
{
    std::cout << "HumanB " << this->_name << " destructor called" << std::endl;
}

void HumanB::attack()
{
    if (!this->_weapon || this->_weapon->getType() == "")
        std::cout << this->_name << " has no weapon" << std::endl;
    else
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}