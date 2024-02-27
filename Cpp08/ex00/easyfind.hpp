

#include <algorithm>
#include <vector>
#include <list>
#include <iostream>

template<typename T>
void easyfind(T container, int needle)
{
    if (std::find(container.begin(), container.end(), needle) != container.end())
        std::cout << "Found\n";
    else
        std::cout << "Not Found\n";
}