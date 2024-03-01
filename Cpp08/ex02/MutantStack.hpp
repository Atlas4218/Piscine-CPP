template<typename T>
class MutantStack
{
private:
    /* data */
public:
    MutantStack(void);
    MutantStack(const MutantStack &stack);
    ~MutantStack();
    MutantStack &operator=(const MutantStack &rhs);

    T top();

    bool empty();
    size_t size();

    void push(T element);
    void pop();

    iterator begin();
    iterator end();
};
