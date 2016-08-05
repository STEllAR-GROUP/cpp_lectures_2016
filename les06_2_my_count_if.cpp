#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>

bool is_odd(int v)
{
    return (v % 2) != 0;
}

template <typename Iterator, typename F>
int my_count_if(Iterator b, Iterator e, F f)
{
    int count = 0;
    while (b != e)
    {
        if (f(*b))
            ++count;
        ++b;
    }
    return count;
    
}

int main()
{
    std::vector<int> v = { 1, 4, 3, 6, 8, 9, 10};
    std::cout << std::count_if(v.begin(), v.end(), is_odd) << std::endl;
    return 0;
}

