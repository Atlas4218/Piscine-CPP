#include <iostream>
#include <string>

class Weapon
{
private:
    std::string type;
public:
    Weapon(std::string str);
    ~Weapon();
    std::string &getType(void);
    void setType(std::string str);

};

