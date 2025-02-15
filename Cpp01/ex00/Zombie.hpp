/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:01:21 by rastie            #+#    #+#             */
/*   Updated: 2024/01/07 15:27:21 by rastie           ###   ########.fr       */
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
    Zombie(std::string name);
    ~Zombie();
    void    announce(void);
    void    setName(std::string name);
};
void    randomChump(std::string name);
Zombie *newZombie(std::string name);

#endif