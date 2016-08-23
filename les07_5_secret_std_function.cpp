#include <functional>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>
#include <numeric>

template <typename T>
void print(T t)
{
    std::cout << t << std::endl;
    
}

// this is secret; I don't see it; its binary library
int secret(std::function<int(int)>f)
{
return f(42);
}

// my code, a global function
int foo(int val)
{
    return 2 * val;
}

int main()
{
    int n = 4;
    print (secret(&foo)); 
    // or instead of passing a global function pass a lambda
    print (secret([](int val) -> int {return 3 * val; }));
// adding a capture gives a compile error
    print (secret([n](int val) -> int {return n * val; }));
    return 0;
}

