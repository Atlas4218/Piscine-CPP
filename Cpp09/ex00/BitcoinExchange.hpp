/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:02:05 by rastie            #+#    #+#             */
/*   Updated: 2024/03/16 20:48:53 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

class BitcoinExchange
{
private:
    std::string _filename;
    std::map<std::string, float> _data;
    std::fstream _fileDatabase;
    std::fstream _fileEntry;

    
public:
    BitcoinExchange(void);
    BitcoinExchange(std::string fileData);
    BitcoinExchange(const BitcoinExchange& bitcoinExchange);
    BitcoinExchange &operator=(const BitcoinExchange &rhs);
    ~BitcoinExchange();

    void initDataBase(void);

    void exchange(std::string filename);

        void setDatabaseFilename(std::string filename);
    class BadDateFormat: public std::exception
    {
    public:
            virtual const char* what() const throw() {return "Bad Date Format";}
    };

    class InvalidDate: public std::exception
    {
    public:
            virtual const char* what() const throw() {return "Bad Date Value";}
    };
    class BadBtcValue: public std::exception
    {
    public:
            virtual const char* what() const throw() {return "Bad monetary Value";}
    };
    class NegativeNumber: public std::exception
    {
    public:
            virtual const char* what() const throw() {return "Not a positive number";}
    };
    class NumberTooLarge: public std::exception
    {
    public:
            virtual const char* what() const throw() {return "Too large a number";}
    };
    class TooEarlyDate: public std::exception
    {
    public:
            virtual const char* what() const throw() {return "Database doesn't go that far back in time";}
    };
};