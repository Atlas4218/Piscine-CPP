/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:59:48 by rastie            #+#    #+#             */
/*   Updated: 2024/03/07 15:50:58 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iostream>

class Span
{
private:
    unsigned int _size;
    std::vector<int> vector;
public:
    Span(void);
    Span(const Span &array);
    Span &operator=(const Span &rhs);
    ~Span();

    Span(unsigned int size);

    template<typename T>
    void addNumber(T iterator);
    void addNumber(int i);

    int shortestSpan();
    int longestSpan();
};

template <typename T>
inline void Span::addNumber(T iterator)
{
    if (iterator.size() + vector.size() > _size)
        throw std::out_of_range("Span::addNumber(T iterator): not enough space to add number(s)");
    vector.push_back(iterator);
}