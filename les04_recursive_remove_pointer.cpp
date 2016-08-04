#include <iostream>
#include <typeinfo>

// main template is the case where it is not a pointer so nothing should happen
// just return the type
template <typename T>
struct recursive_remove_pointer 
{
    typedef T type;
};

// specialized template is the case where it is a pointer and we return the base
// type
template <typename T>
struct recursive_remove_pointer<T*>
{
    typedef typename recursive_remove_pointer<T>::type type;
};

int main()
{
    std::cout << typeid(recursive_remove_pointer<int*****>::type).name() << std::endl;
    
    return 0;
    }


