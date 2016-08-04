#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>

bool is_palindrome(std::string s)
{
    return std::equal( s.begin(), s.end(), s.rbegin() );
}

int main()
{
    std::cout << "madam is a palindrome " << is_palindrome("madam") << std::endl;
    std::cout << "test is a palindrome " << is_palindrome("test") << std::endl;
    std::cout << "racecar is a palindrome " << is_palindrome("racecar") << std::endl;
    return 0;
}

