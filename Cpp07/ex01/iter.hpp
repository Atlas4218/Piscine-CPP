#include <iostream>
#include <string>

template <typename A>
void iter(A *array, int lenght, void (*function)(A const &element))
{
    for (int i = 0; i < lenght; i++)
        function(array[i]);
    
}