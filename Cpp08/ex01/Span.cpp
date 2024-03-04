#include "Span.hpp"

Span::Span(void)
{
}

Span::Span(const Span &array)
{
    *this = array;
}

Span &Span::operator=(const Span &rhs)
{
    if (this != &rhs)
        list = rhs.list;
    return (*this);
}

Span::~Span()
{
}

Span::Span(unsigned int size): _size(size)
{
}

void Span::addNumber(int i)
{
    if (list.size() == _size)
        throw std::out_of_range("Span::addNumber(int i): not enough space to add number");
    list.push_back(i);
}

int Span::shortestSpan()
{
    int span;
    int min;
    if (list.size() <= 1)
        throw std::length_error("Span::shortestSpan: too few item to find span");
    {
        std::list<int> temp = list;
        temp.sort();
        min = temp.front();
        temp.pop_front();
        span = temp.front() - min;
    }
    return (span);
}

int Span::longestSpan()
{
    int span;
    if (list.size() <= 1)
        throw std::length_error("Span::longestSpan: too few item to find span");
    {
        std::list<int> temp = list;
        temp.sort();
        span = temp.back() - temp.front();
    }
    return (span);
}