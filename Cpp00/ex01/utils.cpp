/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:54:20 by rastie            #+#    #+#             */
/*   Updated: 2024/01/05 18:50:55 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <stdlib.h>
void take_input(std::string &input)
{
    std::getline(std::cin, input);
    if (std::cin.eof())
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        exit(1);
    }
}