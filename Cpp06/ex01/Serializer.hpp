/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:01:28 by rastie            #+#    #+#             */
/*   Updated: 2024/02/19 19:41:50 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <iostream>
# include <stdint.h>
# include <string>
typedef struct data_s
{
    std::string name;
} Data;

class Serializer
{
private:
    /* data */
    Serializer(void);
    Serializer(Serializer &src);
    Serializer &operator=(Serializer rhs);
    ~Serializer();
public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);    
};

#endif