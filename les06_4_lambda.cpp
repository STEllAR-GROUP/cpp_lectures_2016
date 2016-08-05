#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>

int main()
{
    std::vector<std::string> v = { "abcdefg", "a", "decfg", "df"};
    
    int len = 3;
    std::cout 
        << std::count_if(v.begin(), v.end(), 
             [len](std::string s)
             {
                  return s.size() < len;
             })
        << std::endl;
    
    return 0;
}

