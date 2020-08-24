#include <iostream>
#include <array>

template <class InputIterator, class Function>
void foreach(InputIterator first, InputIterator last, Function fn)
{
    while(first != last)
    {
        fn(*first);
        ++first;
    }
}

// g++ -o foreach14 foreach14.cpp --std=c++14
int main()
{
    std::array<int, 3> arr = { 2, 3, 4 };
    std::string str = "hello";

    foreach(arr.begin(), arr.end(), [](auto& e){e *= e;});
    foreach(str.begin(), str.end(), [](auto& e){e -= 32;});

    for(const auto& e : arr)
        std::cout<<e<<std::endl;
    std::cout<<str<<std::endl;
}
