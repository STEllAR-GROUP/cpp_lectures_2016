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

int main()
{

    std::vector<int> v = {1, 2, 3, 5, 9, 42};
    
    int n =3;
    std::transform(v.begin(), v.end(), v.begin(),
       std::bind(&add, n, std::placeholders::_1 ));

    for(int i : v)
        std::cout << i << std::endl;
    
    return 0;
}

