/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:04:28 by rastie            #+#    #+#             */
/*   Updated: 2024/01/07 16:36:41 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>
# include <iostream>

class Zombie
{
private:
    /* data */
    std::string _name;

public:
    Zombie();
    ~Zombie();
    void    announce(void);
    void    setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );
#endif