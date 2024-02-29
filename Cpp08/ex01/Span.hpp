#include <vector>
#include <stdexcept>
#include <algorithm>
class Span
{
private:
    std::vector<int> vector;
public:
    Span(void);
    Span(Span &array);
    Span &operator=(Span &rhs);
    ~Span();

    Span(unsigned int size);

    void addNumber(int i);

    int shortestSpan();
    int longestSpan();
};