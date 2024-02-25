template<typename A, typename F>
void iter(A *array, int lenght, F (*function)(A element))
{
    while (*array)
    {
        function(*array++);
    }
    
}