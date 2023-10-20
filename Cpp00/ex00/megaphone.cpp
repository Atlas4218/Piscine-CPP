/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:17:52 by rastie            #+#    #+#             */
/*   Updated: 2023/10/10 20:57:54 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "LOUD AND ANNOYING FEEDBACK NOISE" << std::endl;
	av++;
	while (*av)
	{
		std::cout << std::uppercase << *av;
		av++;
	}
	std::cout << std::endl;
	return (0);
}
