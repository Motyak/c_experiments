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
        function_t first = (function_t)increment;
        function_t second = (function_t)square;
        function_t third = (function_t)decrement;
        
        pipeline_t inc_then_double_then_dec = pipe(first, second, third);
        generic_t input = (generic_t)9;
        generic_t res = inc_then_double_then_dec(input);
        printf("%ld\n", (uintptr_t)res); // 99
    }

    {
        function_t first = (function_t)increment;
        function_t second = (function_t)increment;
        
        pipeline_t next_next_char = pipe(first, second);
        generic_t input = (generic_t)'A';
        generic_t res = next_next_char(input);
        printf("%c\n", (char)(uintptr_t)res); // C
    }
}
