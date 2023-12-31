/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:17:52 by rastie            #+#    #+#             */
/*   Updated: 2023/12/31 15:26:53 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstring>
#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "LOUD AND ANNOYING FEEDBACK NOISE";
	av++;
	while (*av)
	{
		for (size_t i = 0; i < std::strlen(*av); i++)
			(*av)[i] = std::toupper((*av)[i]);
		std::cout << *av;
		av++;
	}
	std::cout << std::endl;
	return (0);
}
