/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:10:27 by rastie            #+#    #+#             */
/*   Updated: 2023/12/31 14:10:52 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <iostream>
#include <string>

class Weapon
{
private:
    std::string type;
public:
    Weapon(std::string str);
    ~Weapon();
    std::string &getType(void);
    void setType(std::string str);

};
#endif