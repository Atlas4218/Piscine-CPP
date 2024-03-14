#include "RPN.hpp"



bool isAllDigit(const char *str)
{
    if (*str == '-' || *str == '+')
        str++;
    if (!*str)
        return (false);
    while (*str)
        if (!isdigit(*(str++)))
            return (false);
    return (true);
}
void calculationRNP(char *rpn)
{
    std::istringstream stream(rpn);
    int operand1, operand2;
    char *end = 0;
    std::stack<int, std::vector<int> > stack;

    for (std::string arg; std::getline(stream, arg, ' ');)
    {
        if (isAllDigit(arg.c_str()))
            stack.push(std::strtol((arg.c_str()), &end, 10));
        else if ((!std::strcmp(arg.c_str() , "-") || !std::strcmp(arg.c_str(), "+") || std::strcmp(arg.c_str(), "*") || std::strcmp(arg.c_str(),  "/")))
        {
            if (stack.size() < 2)
            {
                std::cout << "Error\n";
                return ;
            }
            operand2 = stack.top();
            stack.pop();
            operand1 = stack.top();
            stack.pop();
            switch (*arg.c_str())
            {
            case '+':
                stack.push(operand1 + operand2);
                break;
            case '*':
                stack.push(operand1 * operand2);
                break;
            case '-':
                stack.push(operand1 - operand2);
                break;
            case '/':
                if (!operand2)
                {
                    std::cout << "Error: division by 0\n";
                    return ;
                }
                else
                    stack.push(operand1 / operand2);
                break;
            default:
                break;
            }
        }
        else
        {
            std::cout << "Error\n";
            break ;
        }
    }
    if (stack.size() != 1)
        std::cout << "Error\n";
    else
        std::cout << stack.top() << std::endl;
}
