#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>
#include <numeric>

int main()
{

    std::vector<int> v = {1, 2, 3, 5, 9, 42};
    
    int n =3;
    std::transform(v.begin(), v.end(), v.begin(),
       [n](int val)
       {
           return val * n;        
       });

    for(int i : v)
        std::cout << i << std::endl;
    
    return 0;
}

