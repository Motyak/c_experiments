#include <stdio.h>
#include <stdarg.h>

#define add(...) add(__VA_ARGS__, 0);
int (add)(int a, int b, ...) {
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

int main()
{
    int res = add(1, 2, 3, 4, 5);
    printf("%d\n", res);
}
