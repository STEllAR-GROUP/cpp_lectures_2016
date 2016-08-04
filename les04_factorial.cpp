#include <iostream>

template <int N>
struct factorial
{
    static int const value = N * factorial<N-1>::value;
};

template <>
struct factorial<1>
{
    static int const value = 1;
};


int main()
{
    // creat two different types using the integers 1 and 2
    std::cout << factorial<10>::value << std::endl;
    
    factorial<2> f2;
    return 0;
}


