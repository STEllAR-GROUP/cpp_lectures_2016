#include <functional>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>
#include <numeric>

template <typename T>
void print(T t)
{
    std::cout << t << std::endl;
    
}

int foo(int value)
{
    print(value);
    ++value;
    print(value);
    return value;
}

int main()
{
    int i = 42;
    int j = foo(i);
    print(i);
    print(j);
    return 0;
}

