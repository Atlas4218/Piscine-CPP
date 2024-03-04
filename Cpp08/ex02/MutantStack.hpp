/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:02:21 by rastie            #+#    #+#             */
/*   Updated: 2024/03/04 15:28:51 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <deque>
#include <iostream>


template< typename T, class Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
private:
    /* data */
public:
    MutantStack(void) {}
    MutantStack(const MutantStack &stack) {*this = stack;}
    ~MutantStack() {}
    MutantStack &operator=(const MutantStack &rhs)
    {
        std::stack<T, Container>::operator=(rhs);
        return *this;
    }
    typedef typename Container::iterator iterator;
    iterator begin() {return this->c.begin();}
    iterator end() {return this->c.end();}
};
