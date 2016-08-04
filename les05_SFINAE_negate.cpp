#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

//using a double ends up using SFINAE to substitute an int since typedef is not
//defined
//negate an integer or anything else

struct foo
{
    foo(int i) : data(i) {}
    
    foo negate() { return foo(-1); }

    int data;
};

//Whenever I want to negate an integer 
int negate(int i)
{
    return -i;
}

//Not an integer return a type that is defined by the type itself
template <typename T>
typename T::return_value negate(T v)
{
    return v.negate();
}

int main()
{
    char c ='H' ;
    std::string s;
    std::cout << "negate(true) = " << negate(true) << std::endl; 
    std::cout << "negate(5.2) = " << negate(5.2) << std::endl; 
    std::cout << "negate(2) = " << negate(2) << std::endl; 
    
    return 0;
}

