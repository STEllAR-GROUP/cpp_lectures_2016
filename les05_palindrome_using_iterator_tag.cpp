#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

// rand access iterator have std::random_access_iterator_tag

template <typename T1, typename T2>
struct is_equal : std::false_type
{
};

// specialization
template <typename T>
struct is_equal<T, T> : std::true_type
{
};

template <typename Iterator>
struct is_random_access_iterator
  : is_equal<
        typename std::iterator_traits<Iterator>::iterator_category,
        std::random_access_iterator_tag
    >
{
};

template <typename Iter>
void my_advance(Iter& it, int n, std::false_type)
{
    while(n--)
        ++it;
    std::cout << " my_advance used loop; it did not have a random_access_iterator"
              << std::endl;
}

template <typename Iter>
void my_advance(Iter& it, int n, std::true_type)
{
    it += n;
    std::cout << " my_advance used const; it had a random_access_iterator"
              << std::endl;
}

template <typename Iter>
void my_advance(Iter& it, int n)
{
    return my_advance(it, n, 
        typename is_random_access_iterator<Iter>::type());
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
    std::cout << " palindrome =  " << is_palindrome(l) << ", ";
    for(auto& i : l) std::cout << i ; // print the vector as a word 
    std::cout << std::endl; 
    
    std::list<char> t = {'t', 'e', 's', 't'};
    std::cout << " palindrome =  " << is_palindrome(t) << ", ";
    for(auto& i : t) std::cout << i ; // print the list as a word 
    std::cout << std::endl; 
    return 0;
}

