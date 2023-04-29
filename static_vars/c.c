
#include <stdio.h>
#include <stdbool.h>

#define factorial() factorial(false)
#define clean_factorial() (factorial)(true)
long (factorial)(bool reset_static_variables)
{
    static long res = 1;
    static int n = 1;

    return reset_static_variables?
        res = n = 1 : // throw away return value
        (res *= n++);
}


int main()
{
    {
        long res;
        for (int i = 1; i <= 8; ++i)
        {
            res = factorial();
            printf("%d! = %ld\n", i, res);
        }
        clean_factorial(); // make the function reusable
    }

    printf("\r\n");

    {
        long res;
        for (int i = 1; i <= 8; ++i)
        {
            res = factorial();
            printf("%d! = %ld\n", i, res);
        }
    }
}

