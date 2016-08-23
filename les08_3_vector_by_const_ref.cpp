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

void foo(std::vector<int> const& v)
{
    for (int val : v)
        print(val+1);
}

int main()
{

    std::vector<int> v = { 1, 2, 3, 45, 67 };
    foo(v);
    for (int val : v)
        print(val);
}

