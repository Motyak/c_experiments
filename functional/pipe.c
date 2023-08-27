#include "pipe.h"

#include <stdio.h>
#include <stdint.h>

int increment(int n)
{
    return ++n;
}

int square(int n)
{
    return n * n;
}

int decrement(int n)
{
    return --n;
}

int main()
{
    {
        pipeline_t inc_then_double_then_dec = pipe(
            (function_t)increment,
            (function_t)square,
            (function_t)decrement
        );
        generic_t input = (generic_t)9;
        uintptr_t res = inc_then_double_then_dec(input);
        printf("%ld\n", res); // 99
    }

    {
        pipeline_t next_next_char = pipe(
            (function_t)increment,
            (function_t)increment
        );
        generic_t input = (generic_t)'A';
        uintptr_t res = next_next_char(input);
        printf("%c\n", (char)res); // C
    }
}
