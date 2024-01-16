/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:46:36 by rastie            #+#    #+#             */
/*   Updated: 2024/01/16 22:33:32 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap dummy;
    ClapTrap clap("Clap");
    ClapTrap trap(clap);
    
    dummy = ClapTrap("Bob");

    std::cout << std::endl;
    std::cout << clap.getEnergyPoint() << " energy left for Clap" << std::endl;
    clap.attack("Staff");
    std::cout << clap.getEnergyPoint() << " energy left for Clap" << std::endl;
    
    std::cout << dummy.getHitPoint() << " LP left for Bob" << std::endl;
    dummy.takeDamage(5);
    std::cout << dummy.getHitPoint() << " LP left for Bob" << std::endl;

    dummy.beRepaired(1);
    std::cout << dummy.getHitPoint() << " LP left for Bob" << std::endl;
    std::cout << dummy.getEnergyPoint() << " energy left for Bob" << std::endl;


    dummy.takeDamage(10);
    std::cout << dummy.getHitPoint() << " LP left for Bob" << std::endl;

    dummy.beRepaired(1);
    dummy.takeDamage(10);

    std::cout << "Clap -> Trap (1 energy)" << std::endl;
    trap.setName("Trap");
    trap.setEnerergyPoint(1);

    std::cout << trap.getEnergyPoint() << " energy left for Trap" << std::endl;
    trap.attack("Bob");
    std::cout << trap.getEnergyPoint() << " energy left for Trap" << std::endl;
    trap.attack("Bob");

    std::cout << std::endl;


    return 0;
}