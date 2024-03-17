/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 19:51:43 by rastie            #+#    #+#             */
/*   Updated: 2024/03/16 23:58:19 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <deque>
#include <utility>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <cerrno>


class PmergeMe
{
private:
    std::vector<unsigned int> _vector;
    std::deque<unsigned int> _deque;
    
    template <typename T>
    typename std::deque<T>::iterator binarySearch(typename std::deque<T>::iterator low,
                                             typename std::deque<T>::iterator high,
                                             T &value);
                                             
    template <typename T>
    typename std::vector<T>::iterator binarySearch(typename std::vector<T>::iterator low,
                                             typename std::vector<T>::iterator high,
                                             T &value);
    template <typename T>
    void sortFordJonhson(std::deque<T> &tab);

    template <typename T>
    void sortFordJonhson(std::vector<T> &tab);
    
    PmergeMe(void);
    
public:
    PmergeMe(char **array);
    PmergeMe(PmergeMe &pmerge);
    PmergeMe &operator=(PmergeMe &rhs);
    ~PmergeMe();

    void sort();
};
