#include <list>
#include <stdexcept>
#include <algorithm>
#include <iostream>
class Span
{
private:
    unsigned int _size;
    std::list<int> list;
public:
    Span(void);
    Span(const Span &array);
    Span &operator=(const Span &rhs);
    ~Span();

    Span(unsigned int size);

    void addNumber(int i);
    template<typename T>
    void addNumber(T iterator);

    int shortestSpan();
    int longestSpan();
};

template <typename T>
inline void Span::addNumber(T iterator)
{
    if (iterator.size() + list.size() > _size)
        throw std::out_of_range("Span::addNumber(T iterator): not enough space to add number(s)");
    list.push_back(iterator);
}
