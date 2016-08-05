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
int main()
{
    std::vector<int> v = { 1, 4, 3, 6, 8, 9, 10};
    std::cout << std::count_if(v.begin(), v.end(), is_odd) << std::endl;
    return 0;
}

