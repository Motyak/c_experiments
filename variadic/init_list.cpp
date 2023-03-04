#include <iostream>

using ints = std::initializer_list<int>;

int add(ints args) {
    int res = 0;
    for (int arg: args) {
        res += arg;
    }
    return res;
}

// g++ --std=c++11 init_list.cpp -o init_list
int main()
{
    
    {
        int res = add({});
        std::cout << res << std::endl;
    }
    
    {
        int res = add({3, 2, 4});
        std::cout << res << std::endl;
    }
    
}
