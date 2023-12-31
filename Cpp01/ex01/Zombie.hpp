#include <string>
#include <iostream>

class Zombie
{
private:
    /* data */
    std::string _name;

public:
    Zombie(std::string name);
    ~Zombie();
    void    annouce(void);
    void    setName(std::string name)
};

Zombie* zombieHorde( int N, std::string name )
