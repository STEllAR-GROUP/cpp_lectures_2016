#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>

template <typename Iter>
void my_advance(Iter& it, int n)
{
    while(n--)
        ++it;
}

template <typename Container>

bool is_palindrome(Container s)
{
    auto middle = s.begin();
    //std::advance( middle, s.size() / 2 );
    my_advance( middle, s.size() / 2 );
    return std::equal( s.begin(), middle, s.rbegin() );
}

int main()
{
    std::vector<char> l = {'m', 'a', 'd', 'a', 'm'};
    for(auto& i : l) std::cout << i ; // print the vector as a word 
    std::cout << " is a palindrome: " << is_palindrome(l) << std::endl;
    
    std::vector<char> t = {'t', 'e', 's', 't'};
    for(auto& i : t) std::cout << i ; // print the vector as a word 
    std::cout << " is a palindrome: " << is_palindrome(t) << std::endl;
    
    return 0;
}
