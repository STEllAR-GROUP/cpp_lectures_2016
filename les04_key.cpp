#include <iostream>
#include <typeinfo>

template <typename Key, typename Value>
struct make_map 
{
    typedef ;
};

int main()
{
    std::cout << typeid(add_pointer<int>::type).name() << std::endl;
    std::cout << typeid(add_pointer<add_pointer<int>::type>::type).name() << std::endl;
    add_pointer<int>::type foo= 0;
    
    return 0;
}


