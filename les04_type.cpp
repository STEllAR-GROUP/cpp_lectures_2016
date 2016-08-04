#include <iostream>
#include <typeinfo>

template <typename T>
struct add_pointer 
{
    typedef T* type;
};

int main()
{
    std::cout << typeid(add_pointer<int>::type).name() << std::endl;
    std::cout << typeid(add_pointer<add_pointer<int>::type>::type).name() << std::endl;
    add_pointer<int>::type foo= 0;
    
    return 0;
    }


