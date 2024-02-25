template<typename T>
class Array
{
private:
    T *element
public:
    Array(void);
    Array(unsigned int n);
    Array(Array<T> array);
    Array<T> &operator=(Array<T> &rhs);
    ~Array();
};
