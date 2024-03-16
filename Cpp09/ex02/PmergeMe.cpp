#include <list>
#include <deque>
#include <algorithm>

/*using list*/
template <typename T>
void sortFordJonhsonList(std::list<T> &tab)
{
    std::list<int> test = {5,8,4,6,7,9,1,2,3,0};

    /*make pairs*/
    std::list<std::pair<T, T> > recur;
    T *remain = 0;
    if (tab.size() <= 1)    //recur break case, no pair can be made
        return ;
    while (tab.size())
    {
        std::list<int>::iterator next = tab.begin();
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
    sortFordJonhsonList(recur);

    /*merge*/
    std::list<std::pair<T, T> >::iterator it = recur.begin()
    tab.push_back((*it).second);    //add first element
    tab.push_back((*it).first);
    if(remain)  //add floating element that wasn't put in a pair
    {
        int pos = binarySearchList(tab.begin(), tab.end(), *remain);
        tab.insert(pos, *remain);
    }

    /*initialisation jaboc numbers*/
    int i = 1;
    int n = 2;
    int j;
    while(it != recur.end())
    {
        j = i;
        i = 2^(n++) - i;
        j = i - j;
        std::list<std::pair<T, T> >::iterator preced_group = it;    //getting the end of the previous group
        std::advance(it, std::min(j, std::distance(it, recur.end()));   //getting the end of a group
        /*adding keys of the group*/
        for (int i = 1; preced_group[i] <= it; i++)
            tab.push_back(preced_group[i].first);
        while (it != preced_group)
        {
            std::list<T>::iterator max = binarySearchList(tab.begin(), tab.end(), (*it).first); //searching keys of the group (> element we're trying to insert)
            std::list<T>::iterator pos = binarySearchList(tab.begin(), max, (*it).second);  //getting the pos to insert the element
            tab.insert(pos, (*it).second); 
            std::advance(it, -1);   //going from the end of the group to the begining
        }
        std::advance(it, std::min(j, std::distance(it, recur.end())));  //resetting the iterator to the end of the group
    }
}

template <typename T>
typename std::list<T>::iterator binarySearchList(typename std::list<T>::iterator low,
                                             typename std::list<T>::iterator high,
                                             T &value)
{  
    if (std::distance(first, last) < 2)
	{
		if (val < *first)
			return first;
		return last;
	}
    typename std::list<T>::iterator mid = low + (std::distance(low, high) / 2);
    if (*mid < value)
        return binarySearchList(mid, high, value);
    return binarySearchList(low, mid, value);
}

/*using deque*/
template <typename T>
void sortFordJonhsonDeque(std::deque<T> &tab)
{
    std::deque<int> test = {5,8,4,6,7,9,1,2,3,0};

    /*make pairs*/
    std::deque<std::pair<T, T> > recur;
    T *remain = 0;
    if (tab.size() <= 1)    //recur break case, no pair can be made
        return ;
    while (tab.size())
    {
        std::deque<int>::iterator next = tab.begin();
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
    sortFordJonhsonDeque(recur);

    /*merge*/
    std::deque<std::pair<T, T> >::iterator it = recur.begin()
    tab.push_back((*it).second);    //add first element
    tab.push_back((*it).first);
    if(remain)  //add floating element that wasn't put in a pair
    {
        int pos = binarySearchDeque(tab.begin(), tab.end(), *remain);
        tab.insert(pos, *remain);
    }

    /*initialisation jaboc numbers*/
    int i = 1;
    int n = 2;
    int j;
    while(it != recur.end())
    {
        j = i;
        i = 2^(n++) - i;
        j = i - j;
        std::deque<std::pair<T, T> >::iterator preced_group = it;    //getting the end of the previous group
        std::advance(it, std::min(j, std::distance(it, recur.end()));   //getting the end of a group
        /*adding keys of the group*/
        for (int i = 1; preced_group[i] <= it; i++)
            tab.push_back(preced_group[i].first);
        while (it != preced_group)
        {
            std::deque<T>::iterator max = binarySearchDeque(tab.begin(), tab.end(), (*it).first); //searching keys of the group (> element we're trying to insert)
            std::deque<T>::iterator pos = binarySearchDeque(tab.begin(), max, (*it).second);  //getting the pos to insert the element
            tab.insert(pos, (*it).second); 
            std::advance(it, -1);   //going from the end of the group to the begining
        }
        std::advance(it, std::min(j, std::distance(it, recur.end())));  //resetting the iterator to the end of the group
    }
}

template <typename T>
typename std::deque<T>::iterator binarySearchDeque(typename std::deque<T>::iterator low,
                                             typename std::deque<T>::iterator high,
                                             T &value)
{  
    if (std::distance(first, last) < 2)
	{
		if (val < *first)
			return first;
		return last;
	}
    typename std::deque<T>::iterator mid = low + (std::distance(low, high) / 2);
    if (*mid < value)
        return binarySearchDeque(mid, high, value);
    return binarySearchDeque(low, mid, value);
}
