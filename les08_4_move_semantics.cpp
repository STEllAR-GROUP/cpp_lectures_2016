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

std::vector<int> foo(std::vector<int> v)
{
    print("pointer of vector in function foo");
    print(v.data()); //prints pointer of vector
    for (int val : v)
        print(val);
    return v;
}

int main()
{

    std::vector<int> v = { 1, 2, 3, 45, 67 };
    print("pointer of v in main before calling foo");
    print(v.data());
    std::vector<int> v1 = foo(v);
    print("pointer of v1 in main after calling foo");
    print(v1.data());
}

