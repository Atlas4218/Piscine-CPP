/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:17:30 by rastie            #+#    #+#             */
/*   Updated: 2024/02/19 19:30:55 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
   Data *data = new Data;

    data->name = "achraf";

    std::cout << "Name: " << Serializer::deserialize( Serializer::serialize( data ) )->name << std::endl;

    delete data;
    return (0);
}