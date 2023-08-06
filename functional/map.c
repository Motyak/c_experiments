
#include "map.h"

#include <stdio.h>
#include <stdint.h>

int times2(int n)
{
    return n * 2;
}

char uppercase(char c)
{
    if (97 <= c && c <= 122)
        return c - 32;
    return c;
}

int main()
{
    {
        function_t fn = (function_t)times2;
        int arr[] = { 1, 2, 3 };
        struct container_t container = {arr, sizeof(arr), sizeof(int)};
        struct container_t res = map(fn, container);
        for (size_t i = 0; i < res.size / res.itemsize; ++i)
        {
            printf("%d ", ((int*)res.items)[i]); // 2 4 6
        }
        printf("\n");
    }

    {
        function_t fn = (function_t)uppercase;
        char str[] = "c0ol_";
        struct container_t container = {str, sizeof(str), sizeof(char)};
        struct container_t res = map(fn, container);
        for (size_t i = 0; i < res.size / res.itemsize; ++i)
        {
            printf("%c", ((char*)res.items)[i]); // C0OL_
        }
        printf("\n");
    }
}
