#include "Span.hpp"

Span::Span(void){}

Span::Span(const Span &array)
{
    *this = array;
}

Span &Span::operator=(const Span &rhs)
{
    if (this != &rhs)
        vector = rhs.vector;
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
    if (vector.size() == _size)
        throw std::out_of_range("Span::addNumber(int i): not enough space to add number");
    vector.push_back(i);
}

int Span::shortestSpan()
{
    int span = INT_MAX;
    int nb = INT_MIN;
    if (vector.size() <= 1)
        throw std::length_error("Span::shortestSpan: too few item to find span");
    
    for (size_t i = 0; i < vector.size(); i++)
    {
        nb = vector[i];
        for (size_t j = i + 1; j < vector.size(); j++)
            if (std::abs(nb - vector[j]) < span)
                span = std::abs(nb - vector[j]);
    }
    return (span);
}

int Span::longestSpan()
{
    if (vector.size() <= 1)
        throw std::length_error("Span::longestSpan: too few item to find span");
    int span =  *std::max_element(vector.begin(), vector.end()) 
                - *std::min_element(vector.begin(), vector.end());
    return (span);
}