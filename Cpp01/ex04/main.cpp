/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:16:50 by rastie            #+#    #+#             */
/*   Updated: 2024/01/03 16:09:04 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    std::fstream file;
    std::fstream file_replace;
    std::string filename;
    std::string hay;
    std::string needle;
    int pos;
    size_t lenght;

    if (ac != 4)
    {
        std::cerr << "Mauvais nombre d'arguments" << std::endl;
        return (1);
    }

    filename = av[1];
    needle = av[2];
    file.open(av[1], std::fstream::in);
    if (!file.is_open())
    {
        std::cerr << "Erreur d'ouverture du fichier d'entree" << std::endl;
        return (2);
    }
    file_replace.open(filename.append(".replace").c_str(), std::fstream::out);
    if (!file_replace.is_open())
    {
        std::cerr << "Erreur d'ouverture du fichier de sortie" << std::endl;
        file.close();
        return (2);
    }

    file.seekg(0, file.end);
    lenght = file.tellg();
    char   buff[lenght];
    file.seekg(0, file.beg);
    file.read(buff, lenght);
    if (!file)
    {
        std::cerr << "Erreur de lecture" << std::endl;
        return (3);
    }

    file.close();
    hay = buff;
    pos = hay.find(needle);
    while ((size_t)pos != (size_t)std::string::npos)
    {
        hay.erase(pos, needle.length());
        hay.insert(pos, av[3]);
        pos = hay.find(needle, pos);
    }
    file_replace.write(hay.c_str(), hay.length());
    file_replace.close();
}
