#include <iostream>
#include <cassert>
const int N = 100;

template <typename T>

T func(T* arr, int n)
{
    T sum = 0;
    for (int i = 0; i<n ;i++)
        sum+=arr[i];
    return sum;
}
template <typename T>
class Stack
{
    private:
        T elems[N];
        int point;
    public:
        Stack();
        T top() const;
        bool push (const T&);
        bool pop();
        bool empty() const;
        void print()const;
};
template <typename T>
inline Stack<T>::Stack() : point(0) {}

template <typename T>
inline bool Stack<T>::push (const T& other)
{
    if (point >= N) return false;

    ///should be predefined operator= for T
    this->elems[point] = other;
    point++;
    return true;
}
template <typename T>
inline bool Stack<T>::pop()
{
    if (empty())
    {
        return false;
    }
    --point;
    return true;
}
template <typename T>
inline T Stack<T>::top() const
{
    assert(!empty());
    return this->elems[point - 1];
}
template <typename T>
inline bool Stack<T>::empty() const
{
    return point == 0;
}
template <typename T>
inline void Stack<T>::print() const
{
    if (empty()) std::cout<<"Empty"<<std::endl;
    else {
        for (int i = point - 1; i>=0; i--)
        {
            ///should be predefined operator<< for T
            std::cout<<elems[i]<<" ";
        }
        std::cout<<std::endl;
    }
}

int main ()
{
    /// template funcs tests
    double A[]={1.1,2.5,3.1,4.4,5};
    int B[] = {1,2,3,4,5};
    std::cout<<func(A,5)<<std::endl;
    std::cout<<func(B,5)<<std::endl;

    /// template stack tests
    Stack<int> st;
    Stack<char> st1;

    st.print();

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    st.print();

    st1.push('a');
    st1.push('b');
    st1.push('c');
    st1.push('d');
    st1.push('e');

    st1.print();

    return 0;
}
