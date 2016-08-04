#include <iostream>
#include <typeinfo>


// these types are in std:: struct true_type 
struct my_true_type 
{
    static bool const value = true;
    typedef my_true_type type;
};

struct my_false_type 
{
    static bool const value = false;
    typedef my_false_type type;
};

//main template will be used if T is not a pointer
template <typename T>
struct is_pointer : my_false_type
{
};

template <typename T>
struct is_pointer<T*> : my_true_type
{
};

int main()
{
    std::cout << typeid(is_pointer<int***>::type).name() << std::endl;
    std::cout << is_pointer<int***>::value << std::endl;
    
    return 0;
    }


