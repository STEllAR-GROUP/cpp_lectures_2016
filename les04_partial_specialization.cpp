#include <iostream>
#include <typeinfo>

template <bool flag, typename T1, typename T2>
struct if_ 
{
    typedef T1 type;
};

template <typename T1, typename T2>
struct if_<false, T1, T2> 
{
    typedef T2 type;
};

int main()
{
    std::cout << typeid(if_<true,  int, double>).name() << std::endl;
    std::cout << typeid(if_<false, int, double>).name() << std::endl;
    
    return 0;
}


