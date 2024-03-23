/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 19:52:16 by rastie            #+#    #+#             */
/*   Updated: 2024/03/23 23:43:16 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename A>
bool parsing(char **arg, A &array)
{
    unsigned int element;
    char *end = 0;
    while (*arg)
    {
        element = std::strtoul(*(arg++), &end, 10);
        if (errno || !element)
            return (false);
        array.push_back(element);
    }
    return (true);
}

template <typename A>
void displayList(A &array)
{
	typename A::const_iterator it = array.begin();
	for (size_t i = 0; i < array.size(); ++i) {
		std::cout << *it;
		if (i + 1 < array.size()) {
			std::cout << ' ';
		}
		++it;
	}
	std::cout << std::endl;
}

/*using deque*/
template <typename T>
void PmergeMe::sortFordJonhson(std::deque<T> &tab)
{
    /*make pairs*/
    std::deque<std::pair<T, T> > recur;
    T *remain = 0;
    if (tab.size() <= 1)    //recur break case, no pair can be made
        return ;
    while (tab.size())
    {
       typename std::deque<T>::iterator next = tab.begin();
        std::advance(next, 1);
        if (next == tab.end())
            remain = &(tab.back());
        else if (tab.front() > *next)
        {
            recur.push_back(std::make_pair(tab.front(), *next));
            tab.pop_front();
        }
        else
        {
            recur.push_back(std::make_pair(*next, tab.front()));
            tab.pop_front();
        }
        tab.pop_front();
    }

    /*recur call*/
    //sortFordJonhson(recur);


    std::deque<T> result;
    tab = result;
    // sorted insertion into the previous array
    typename std::deque<std::pair<T, T> >::iterator it = recur.begin();
    tab.push_back((*it).second);    //add first element
    tab.push_back((*it).first);
    if(remain)  //add floating element that wasn't put in a pair
    {
        typename std::deque<T>::iterator pos = binarySearch(tab.begin(), tab.end(), *remain);
        tab.insert(pos, *remain);
    }

    int i = 1;
    int n = 2;
    int j;
    while(it != recur.end())
    {
        j = i;
        i = (2^(n++)) - i;
        j = i - j;
        typename std::deque<std::pair<T, T> >::iterator preced_group = it;    //getting the end of the previous group
        int rest_size = std::distance(it, recur.end());
        std::advance(it, std::min(j, rest_size));   //getting the end of a group
        typename std::deque<std::pair<T, T> >::iterator tmp = preced_group;
        while(tmp != it)
        {
            tab.push_back((*tmp).first);
            std::advance(tmp, 1);
        }
        while (it != preced_group)
        {
            typename std::deque<T>::iterator max = binarySearch(tab.begin(), tab.end(), (*it).first); //searching keys of the group (> element we're trying to insert)
            typename std::deque<T>::iterator pos = binarySearch(tab.begin(), max, (*it).second);  //getting the pos to insert the element
            tab.insert(pos, (*it).second); 
            std::advance(it, -1);   //going from the end of the group to the begining
        }
        rest_size = std::distance(it, recur.end());
        std::advance(it, std::min(j, rest_size));  //resetting the iterator to the end of the group
    }
    
}

template <typename T>
typename std::deque<T>::iterator PmergeMe::binarySearch(typename std::deque<T>::iterator low,
                                             typename std::deque<T>::iterator high,
                                             T &value)
{  
    if (std::distance(low, high) < 2)
	{
		if (value < *low)
			return low;
		return high;
	}
    typename std::deque<T>::iterator mid = low + std::distance(low, high) / 2;
    if (*mid < value)
        return binarySearch(mid, high, value);
    return binarySearch(low, mid, value);
}

/*using vector*/
template <typename T>
void PmergeMe::sortFordJonhson(std::vector<T> &tab)
{
    /*make pairs*/
    std::vector<std::pair<T, T> > recur;
    T remain = 0;
    if (tab.size() % 2)    //recur break case, no pair can be made
    {
        remain = tab.back();
        tab.pop_back();
    }
    while (tab.size())
    {
        typename std::vector<T>::iterator next = tab.begin();
        std::advance(next, 1);
        if (next == tab.end())
        {
            remain = tab.back();
            tab.pop_back();
            break ;
        }
        else if (tab.front() > *next)
        {
            recur.push_back(std::make_pair(tab.front(), *next));
            tab.pop();
        }
        else
        {
            recur.push_back(std::make_pair(*next, tab.front()));
            tab.pop();
        }
        tab.erase(tab.begin());
    }

    /*recur call*/
    //sortFordJonhson(recur);
   
        
    }
    
}

template <typename T>
typename std::vector<T>::iterator PmergeMe::binarySearch(typename std::vector<T>::iterator low,
                                             typename std::vector<T>::iterator high,
                                             T &value)
{  
    if (std::distance(low, high) < 2)
	{
		if (value < *low)
			return low;
		return high;
	}
    typename std::vector<T>::iterator mid = low + std::distance(low, high) / 2;
    if (*mid < value)
        return binarySearch(mid, high, value);
    return binarySearch(low, mid, value);
}



PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(char **array)
{
    parsing(array, _vector);
    parsing(array, _deque);
}

PmergeMe::PmergeMe(PmergeMe &pmerge)
{
    *this = pmerge;
}


PmergeMe &PmergeMe::operator=(PmergeMe &rhs)
{
    // TODO: insert return statement here
    if (this == &rhs)
        return (*this);
    _deque = rhs._deque;
    _vector = rhs._vector;

    return (*this);
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::sort()
{
    {
        std::cout << "Before: ";
        displayList(_vector);
        clock_t start = clock();
        sortFordJonhson(_vector);
        clock_t end = clock();
        std::cout << "After: ";
        displayList(_vector);
        double time = ((double) (end - start) / (CLOCKS_PER_SEC / 1000000));
        std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector: " << time << "us\n";
    }
    {
        std::cout << "Before: ";
        displayList(_deque);
        clock_t start = clock();
        sortFordJonhson(_deque);
        clock_t end = clock();
        std::cout << "After: ";
        displayList(_deque);
        double time = ((double) (end - start) / (CLOCKS_PER_SEC / 1000000));
        std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque: " << time << "us\n";
    }
}



 std::vector<T> result;
    tab = result;
    typename std::vector<std::pair<T, T> >::iterator it = recur.begin();
    tab.push_back((*it).second);    //add first element
    tab.push_back((*it).first);
    if(remain)  //add floating element that wasn't put in a pair
    {
        typename std::vector<T>::iterator pos = binarySearch(tab.begin(), tab.end(), remain);
        tab.insert(pos, remain);
    }

    int i = 1;
    int n = 2;
    int j;
    while(it != recur.end() && recur.size() > 1)
    {
        j = i;
        i = (2^(n++)) - i;
        j = i - j;
        typename std::vector<std::pair<T, T> >::iterator preced_group = it;    //getting the end of the previous group
        int size_rest = std::distance(it + 1, recur.end());
        std::advance(it, std::min(size_rest, j));   //getting the end of a group
        typename std::vector<std::pair<T, T> >::iterator tmp = preced_group;
        while(tmp != it)
        {
            tab.push_back((*preced_group).first);
            std::advance(tmp, 1);
        }
        while (it != preced_group)
        {
            typename std::vector<T>::iterator max = binarySearch(tab.begin(), tab.end(), (*it).first); //searching keys of the group (> element we're trying to insert)
            typename std::vector<T>::iterator pos = binarySearch(tab.begin(), max, (*it).second);  //getting the pos to insert the element
            tab.insert(pos, (*it).second); 
            std::advance(it, -1);   //going from the end of the group to the begining
        }
        size_rest = std::distance(it, recur.end());
        std::advance(it, size_rest);  //resetting the iterator to the end of the group