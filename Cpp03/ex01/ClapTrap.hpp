/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:54:04 by rastie            #+#    #+#             */
/*   Updated: 2024/01/17 16:24:29 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <string>
# include <iostream>

class ClapTrap
{
	protected:
		std::string _name;
		unsigned int _hitP;
		unsigned int _energyP;
		unsigned int _attackP;

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & orig);
		~ClapTrap(void);

		ClapTrap & operator=(ClapTrap const & rhs);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName(void);
		void setName(std::string name);
		unsigned int getHitPoint(void);
		void setHitPoint(unsigned int hitP);
		unsigned int getEnergyPoint(void);
		void setEnerergyPoint(unsigned int energyP);
		unsigned int getAttackDamage(void);
		void setAttackDamage(unsigned int attackP);
};
#endif
