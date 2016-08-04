#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>
#include <typeinfo>


template <typename T>
struct coordinate
{
    T x, y;
};

template <typename T>
T sqr(T val) { return val * val; }

template <typename T1, typename T2>
decltype(auto) distance(coordinate<T1> lhs, coordinate<T2> rhs) 
    //-> decltype(std::sqrt(sqr(lhs.x - rhs.x) + sqr(lhs.y - rhs.y)))
{
    return std::sqrt(sqr(lhs.x - rhs.x) + sqr(lhs.y - rhs.y));
}

int main()
{

    coordinate<double> c = { 1.0, 2.0 };
    coordinate<float> f { 1.5, 2.5 };

    std::cout << "type = " << typeid(distance(c, f)).name() << std::endl ;
    std::cout << "distance = " << distance(c, f) << std::endl ;

    return 0;
}
