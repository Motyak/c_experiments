#include <iostream>

template <typename T>
T add(T a, T b) {
    return a + b;
}

template <typename T, typename... Targs>
T add(T a, T b, Targs... others) {
    return a + add(b, others...);
}

// g++ --std=c++11 template_recursive.cpp -o template_recursive
int main()
{
    auto res = add(3, 2, 4);
    std::cout << res << std::endl;
}
