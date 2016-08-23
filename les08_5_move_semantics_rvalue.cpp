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

// can now return a vector but with c++11 only the pointer info is returned 
// so vector is not copied

std::vector<int> foo(std::vector<int> && v)
{
    print(v.data());
    return std::move(v);
}

int main()
{

    std::vector<int> v = { 1, 2, 3, 45, 67 };
    print(v.data());
    
    std::vector<int> v1 = foo(foo(std::move(v)));
    print(v1.data());
    print(v.data()); // is zero because data has been moved from here
}

