#include "Span.hpp"

Span::Span(void)
{
}

Span::Span(Span &array)
{
    *this = array;
}

Span &Span::operator=(Span &rhs)
{
    vector = rhs.vector;
    // TODO: insert return statement here
}

Span::~Span()
{
}

Span::Span(unsigned int size)
{
    vector = std::vector<int>(size);
}

void Span::addNumber(int i)
{
    vector.at(vector.size()) = i;
}

int Span::shortestSpan()
{
    if (vector.size() <= 1)
        throw std::length_error("Short::shortestSpan: too few item to find span");

    return 0;
}

int Span::longestSpan()
{
    if (vector.size() <= 1)
        throw std::length_error("Short::longestSpan: too few item to find span");

    return std::max_element(vector.begin(), vector.end()) - std::min_element(vector.begin(), vector.end());
}
