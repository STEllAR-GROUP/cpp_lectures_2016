#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>

int main()
{
    std::vector<int> v = {1, 2, 0, 10, 23, 4};
    
    int len = 3;
    std::cout 
        << std::count_if(v.begin(), v.end(), 
             [len](int i)
             {
                  return i < len;
             })
        << std::endl;
    
    return 0;
}

