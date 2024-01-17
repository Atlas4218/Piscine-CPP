/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:46:36 by rastie            #+#    #+#             */
/*   Updated: 2024/01/17 21:26:32 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	FragTrap dummy;
	FragTrap clap("Clap");
	FragTrap trap(clap);
	ScavTrap scav("Scav");
	FragTrap frag("Frag");
	dummy = FragTrap("Bob");


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


	dummy.takeDamage(300);
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
	
	scav.guardGate();

	std::cout << std::endl;

	frag.highFivesGuys();
	dummy.highFivesGuys();

	std::cout << std::endl;
	return 0;
}
