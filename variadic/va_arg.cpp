#include <iostream>
#include <cstdarg>

int add(int a, int b, ...) {
    va_list args;
    va_start(args, b);
    
    int sumOfArgs = a;
    int currArg = b;
    while (currArg != 0) {
        sumOfArgs += currArg;
        currArg = va_arg(args, int);
    }
    va_end(args);
    
    return sumOfArgs;
}

// g++ --std=c++11 va_arg.cpp -o va_arg
int main()
{
    int res = add(3, 2, 4, 0);
    std::cout << res << std::endl;
}
