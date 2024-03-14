#include "RPN.hpp"
int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error\n";
        return (1);
    }
    calculationRNP(av[1]);
}