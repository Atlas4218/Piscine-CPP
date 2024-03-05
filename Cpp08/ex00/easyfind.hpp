

#include <algorithm>
#include <vector>
#include <vector>
#include <iostream>


class NotFound: public std::exception {

	public:
		const char *what() const throw() {return "Not found";}
};

template < template < typename, typename > class T>
typename T<int, std::allocator<int> >::iterator
    easyfind(T<int, std::allocator<int> > &container, int needle)
{
    typename T<int, std::allocator<int> >::iterator pos;

    pos = std::find(container.begin(), container.end(), needle);
    if (pos == container.end())
        throw NotFound();
    return pos;
}