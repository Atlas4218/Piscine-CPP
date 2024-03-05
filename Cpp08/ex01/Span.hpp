/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:59:48 by rastie            #+#    #+#             */
/*   Updated: 2024/03/05 19:00:04 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

    template<typename T>
    void addNumber(T iterator);
    void addNumber(int i);

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