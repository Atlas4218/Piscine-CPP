/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:06:47 by rastie            #+#    #+#             */
/*   Updated: 2024/01/07 16:52:46 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *strPTR = &str;
    std::string &strREF = str;

    std::cout << &str << ": " << str << std::endl;
    std::cout << strPTR << ": " << *strPTR << std::endl;
    std::cout << &strREF << ": " << strREF << std::endl;

}