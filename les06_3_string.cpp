#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>

//function object

// used this to avoid len as a global
struct shorter_than
{
    //explicit insures that int is not converted to shorter_than type
    explicit shorter_than(int l) : len(l) {}
    
    bool operator()(std::string s)
    { 
    return s.size() < len;   
    }
    
    int len;

};

int main()
{
    std::vector<std::string> v = { "abcdefg", "a", "decfg", "df"};
    
    // created an instance of shorter_than intialized with 3, invokes
    // corresponding constructor which expects one integer
    // use s as if it is a function, invoking the operator which expects a
    // string
    //
//    shorter_than s(3);
//    std::cout << s("abc") << std::endl; //produces false
//    std::cout << s("ab") << std::endl;  //produces true

    std::cout << count_if(v.begin(), v.end(), shorter_than(3)) << std::endl;
    
    return 0;
}

