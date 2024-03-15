#include <list>
#include <algorithm>
template <typename T>
void f(std::list<T> &tab)
{
    std::list<int> test = {5,8,4,6,7,9,1,2,3,0};


    std::list<std::pair<T, T> > recur;
    T remain = 0;
    if (tab.size() == 1)
        return ;
    while (tab.size())
    {
        std::list<int>::iterator next = tab.begin();
        std::advance(next, 1);
        if (next == tab.end())
            remain = tab.back();
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
    f(recur);
    std::list<std::pair<T, T> >::iterator it = recur.begin()
    binary_merge(tab, (*it).second);
    binary_merge(tab, (*it).first);
    std::advance(it, 1);
    //add rest of list
    int i = 0;
    int n = 1;

    while(it != recur.end())
    {
        i = 2^n - i;
        std::list<std::pair<T, T> >::iterator first_group = it;
        std::advance(it, std::min(i, std::distance(it, recur.end()));
        while (it != first_group)
        {
            binary_merge(tab, (*it).second);
            binary_merge(tab, (*it).first);
            std::advance(it, -1);
        }
        std::advance(it, std::min(i, std::distance(it, recur.end()));
    }

    if(remain)
        binary_merge(tab, remain);


       0 1 2 4 8 16 32
       0 1 1 3 5 11 21
        1 0 2 2 6  10
}


7 8 5 9 11 0 2 1 10 3 4 6
.(8 7)(9 5)(11 0)(2 1)(10 3)(6 4)
..((9 5)(8 7))((11 0)(2 1))       ((10 3)(6 4))[a recuperer plus tard]
...(((11 0)(2 1))((9 5)(8 7)))
[](((11 0)(2 1))((9 5)(8 7))) ((10 3)(6 4))
...[((9 5)(8 7))((10 3)(6 4))(((11 0)(2 1))]
..[](((9 5)(8 7))((10 3)(6 4))(((11 0)(2 1)))
..[(8 7)(9 5)]
