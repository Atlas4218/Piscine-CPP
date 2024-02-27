/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:10:23 by rastie            #+#    #+#             */
/*   Updated: 2024/02/27 18:10:24 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
template<typename T>
class Array
{
private:
    T *_element;
    unsigned int _size;
public:
    Array(void): _element(0) {};
    Array(unsigned int n): _size(n) {_element = new T [n];}
    Array<T> &operator=(Array<T> &rhs) {if (_element)
                                            delete[] _element;
                                        _element = new T[rhs._size];
                                        for (unsigned int i = 0; i < rhs._size; i++)
                                            _element[i] = rhs._element[i];
                                        return (*this);}
    Array(Array<T> &array) {*this = array;}
    ~Array() {delete[] _element;}
    T& operator[](std::size_t idx) {if(idx < 0 || idx >= _size)
                                        throw (std::out_of_range("Index out of bounds"));
                                    return  (_element[idx]);}
    unsigned int size() {return (_size);}
};