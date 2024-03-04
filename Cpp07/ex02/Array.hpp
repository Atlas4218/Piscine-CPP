/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <rastie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:10:23 by rastie            #+#    #+#             */
/*   Updated: 2024/03/05 00:05:37 by rastie           ###   ########.fr       */
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
    Array(void): _element(new T[0]), _size(0) {       
         //std::cout << "Default constructor" << std::endl;    
    }

    Array(unsigned int n): _element(new T[n]), _size(n) {
        //std::cout << "Parameter constructor" << std::endl;    
    }
    
    Array<T> &operator=(Array<T> &rhs) {
        //std::cout << "Overload assignment operator" << std::endl;    
        if (this == &rhs) return (*this);
        if (_element) delete[] _element;
        _element = new T[rhs._size];
        for (unsigned int i = 0; i < rhs._size; i++)
            _element[i] = rhs._element[i];
        _size = rhs._size;
        return (*this);
    }   
    Array(Array<T> &array): _element(new T[0]) {
        //std::cout << "Copy constructor" << std::endl;    
        *this = array;
    }
    
    ~Array() {delete[] _element;}
    
    T& operator[](std::size_t idx) {if(idx < 0 || idx >= _size)
                                        throw (std::out_of_range("Index out of bounds"));
                                    return  (_element[idx]);}
    unsigned int size() {return (_size);}
};
