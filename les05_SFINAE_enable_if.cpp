#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

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

template <bool flag, typename T = void>
struct enable_if
{
};

//if the arguement is true we get an embedded typedef
template <typename T>
struct enable_if<true, T>
{
    typedef T type;
};

template <typename Iter>
typename enable_if<!is_random_access_iterator<Iter>::value>::type
my_advance(Iter& it, int n)
{
    while(n--)
        ++it;
    //diagnostic print
    std::cout << " my_advance used loop; it did not have a random_access_iterator"
              << std::endl;
}

template <typename Iter>
typename enable_if<is_random_access_iterator<Iter>::value>::type
my_advance(Iter& it, int n)
{
    it += n;
    //diagnostic print
    std::cout << " my_advance used const; it had a random_access_iterator"
              << std::endl;
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

