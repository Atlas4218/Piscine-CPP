#include <list>
#include <algorithm>
template <typename T>
void f(std::list<T> &tab)
{
    std::list<int> test = {5,8,4,6,7,9,1,2,3,0};

    /*make pairs*/
    std::list<std::pair<T, T> > recur;
    T *remain = 0;
    if (tab.size() == 1)
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
    f(recur);

    /*merge*/
    std::list<std::pair<T, T> >::iterator it = recur.begin()
    tab.push_back((*it).second);    //add first element
    tab.push_back((*it).first);
    std::advance(it, 1);
    if(remain)  //add floating element that wasn't put in a pair
    {
        int pos = binarySearch(tab.begin(), tab.end(), *remain);
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
        std::list<std::pair<T, T> >::iterator preced_group = it;
        std::advance(it, std::min(j - 1, std::distance(it, recur.end()));   //getting the end of a group
        /*adding keys of the group*/
        for (int i = 1; preced_group[i] <= it; i++)
            tab.push_back(preced_group[i].first);
        while (it != preced_group)
        {
            std::list<T>::iterator max = binarySearch(tab.begin(), tab.end(), (*it).first); //searching keys of the group (> element we're trying to insert)
            std::list<T>::iterator pos = binarySearch(tab.begin(), max, (*it).second);  //getting the pos to insert the element
            tab.insert(pos, (*it).second); 
            std::advance(it, -1);   //going from the end of the group to the begining
        }
        std::advance(it, std::min(j + 1, std::distance(it, recur.end())));  //seting the iterator to the begining of the next group
    }
}

template <typename T>
typename std::list<T>::iterator binarySearch(typename std::list<T>::iterator low,
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
        return binarySearch(mid, high, value);
    return binarySearch(low, mid, value);
}

