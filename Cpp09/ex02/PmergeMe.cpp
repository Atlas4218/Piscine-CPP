/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 19:52:16 by rastie            #+#    #+#             */
/*   Updated: 2024/03/25 00:06:14 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename A>
bool parsing(char **args, A &array)
{
    char *end = 0;
    unsigned int element;
    while(*args)
    {
        element = std::strtoul(*args, &end, 10);
        if (errno || element <= 0)
        {
            std::cerr << *args;
            throw std::invalid_argument(": Wrong argument");
        }
        array.push_back(element);
        args++;
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
std::deque<std::pair<T, T> >generate_pair(std::deque<T> &tab)
{
    std::deque<std::pair<T, T> >result;
    while (tab.size())
    {
        typename std::deque<T>::iterator next = tab.begin();
        std::advance(next, 1);

        if (tab.front() < *next)
            std::swap(tab.front(), *next);
        result.push_back(std::make_pair(tab.front(), *next));
        tab.erase(tab.begin());  
        tab.erase(tab.begin());       
    }

    return (result);
}

template <typename T>
void PmergeMe::sortFordJonhson(std::deque<T> &tab)
{
    T remain;
    bool size_odd = tab.size() % 2;
    if (tab.size() <= 1)
        return ;
    if (tab.size() % 2)
    {
        remain = tab.back();
        tab.pop_back();
    }
    std::deque<std::pair<T, T> > recur = generate_pair(tab);
    tab.clear();

    typename std::deque<std::pair<T, T> >::iterator it = recur.begin();
    tab.push_back((*it).second);    //add first element

    for (size_t i = 0; i < recur.size(); i++) 
    {
        typename std::deque<T>::iterator pos = binarySearch(tab.begin(), tab.end(), recur[i].first);
        tab.insert(pos, recur[i].first);
    }
    if(size_odd)  //add floating element that wasn't put in a pair
    {
        typename std::deque<T>::iterator pos = binarySearch(tab.begin(), tab.end(), remain);
        tab.insert(pos, remain);
    }

    
    int i = 1;
    int n = 3;
    int j;
    while (it + 1 != recur.end() && recur.size() > 1)
    {
        j = i;
        i = (std::pow(2, n++)) - i;
        j = i - j;
        typename std::deque<std::pair<T, T> >::iterator preced_group = it;    //getting the end of the previous group
        int size_rest = std::distance(it + 1, recur.end());
        std::advance(it, std::min(size_rest, j));   //getting the end of a group
        while (it != preced_group)
        {
            typename std::deque<T>::iterator max = binarySearch(tab.begin(), tab.end(), (*it).first); //searching keys of the group (> element we're trying to insert)
            typename std::deque<T>::iterator pos = binarySearch(tab.begin(), max, (*it).second);  //getting the pos to insert the element
            tab.insert(pos, (*it).second); 
            std::advance(it, -1);   //going from the end of the group to the begining
        }
        std::advance(it, std::min(size_rest, j));   //getting the end of a group
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
std::vector<std::pair<T, T> >generate_pair(std::vector<T> &tab)
{
    std::vector<std::pair<T, T> >result;
    while (tab.size())
    {
        typename std::vector<T>::iterator next = tab.begin();
        std::advance(next, 1);

        if (tab.front() < *next)
            std::swap(tab.front(), *next);
        result.push_back(std::make_pair(tab.front(), *next));
        tab.erase(tab.begin());  
        tab.erase(tab.begin());       
    }

    return (result);
}

template <typename T>
void PmergeMe::sortFordJonhson(std::vector<T> &tab)
{
    T remain;
    bool size_odd = tab.size() % 2;
    if (tab.size() <= 1)
        return ;
    if (tab.size() % 2)
    {
        remain = tab.back();
        tab.pop_back();
    }
    std::vector<std::pair<T, T> > recur = generate_pair(tab);
    tab.clear();
    
    typename std::vector<std::pair<T, T> >::iterator it = recur.begin();
    tab.push_back((*it).second);    //add first element

    for (size_t i = 0; i < recur.size(); i++) 
    {
        typename std::vector<T>::iterator pos = binarySearch(tab.begin(), tab.end(), recur[i].first);
        tab.insert(pos, recur[i].first);
    }
    if(size_odd)  //add floating element that wasn't put in a pair
    {
        typename std::vector<T>::iterator pos = binarySearch(tab.begin(), tab.end(), remain);
        tab.insert(pos, remain);
    }

    
    int i = 1;
    int n = 2;
    int j;
    while (it + 1 != recur.end() && recur.size() > 1)
    {
        j = i;
        i = (std::pow(2, n++)) - i;
        j = i - j;
        typename std::vector<std::pair<T, T> >::iterator preced_group = it;    //getting the end of the previous group
        int size_rest = std::distance(it + 1, recur.end());
        std::advance(it, std::min(size_rest, j));   //getting the end of a group
        while (it != preced_group)
        {
            typename std::vector<T>::iterator max = binarySearch(tab.begin(), tab.end(), (*it).first); //searching keys of the group (> element we're trying to insert)
            typename std::vector<T>::iterator pos = binarySearch(tab.begin(), max, (*it).second);  //getting the pos to insert the element
            tab.insert(pos, (*it).second); 
            std::advance(it, -1);   //going from the end of the group to the begining
        }
        std::advance(it, std::min(size_rest, j));  //resetting the iterator to the end of the group
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




