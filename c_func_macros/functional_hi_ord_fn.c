
#include <stdio.h>
#include <stdint.h>

#include "reduce.h"

int add(int a, int b)
{
    return a + b;
}

int main()
{
    #define res (int)reduce( \
        /*reducer=*/(reducer_t)add, \
        /*initial=*/(generic_t)0, \
        /*input=*/Container_of(input) \
    )

    #define input (int[]){ }
    printf("%d\n", res);
    #undef input

    #define input (int[]){ 1, 2, 3 }
    printf("%d\n", res);
    #undef input
    
    #undef res
}
