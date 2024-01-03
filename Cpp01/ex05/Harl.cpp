/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:17:58 by rastie            #+#    #+#             */
/*   Updated: 2024/01/03 20:28:01 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}
void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}
void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error(void)
{
    std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}
Harl::Harl(void)
{
    std::cout << "Harl constructor called" << std::endl;
}

Harl::~Harl()
{
    std::cout << "Harl destructor called" << std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::* funct_list [])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    std::string level_list[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    while (i < 4 && level_list[i].compare(level))
        i++;
    if (i < 4)
        (this->*funct_list[i])();

}