#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>
#include <iterator>

//uses accumulate that takes a function
int main()
{
    //using accumulate with lambda to find the sum

    std::vector<int> v = { 2, 4, 3, 6, 8, 9, 10 };
    
    std::cout 
        << std::accumulate(v.begin(), v.end(), 0, 
             [](int sum, int val) { return sum + val; })
        << std::endl;
    
    //using accumulate to find the number of characters in shortest string
    std::vector<std::string> vs = { "abcdefg", "abc", "decfg", "df"};
    std::cout 
        << std::accumulate(vs.begin(), vs.end(),  
                std::numeric_limits<int>::max(),
             [](int shortest, std::string s) -> int
             {
                return (shortest > s.size() ? s.size() : shortest);
             })
        << std::endl;
    
    return 0;
}
