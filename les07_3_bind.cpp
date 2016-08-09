#include <functional>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>
#include <numeric>

int add(int a, int b)
{
     return a + b;
}

template <typename T>
void print(T t)
{
    std::cout << t << std::endl;
}

int main()
{

    int n =3;
       print(std::bind(&add, std::placeholders::_1, n)(3)); // 6
       print(std::bind(&add, std::placeholders::_3, n)(3, 4, 5)); // 8
       print(std::bind(&add, std::placeholders::_3, std::placeholders::_2)(3, 4, 5)); // 9

    
    return 0;
}

