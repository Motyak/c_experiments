
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
        int arr[] = { 1, 2, 3 };
        struct container_t res = map(
            (function_t)times2,
            (struct container_t){ .items=arr, .size=sizeof(arr), .itemsize=sizeof(int) }
        );
        for (size_t i = 0; i < res.size / res.itemsize; ++i)
            printf("%d ", ((int*)res.items)[i]); // 2 4 6
        printf("\n");
    }

    {
        char str[] = "c0ol_";
        struct container_t res = map(
            (function_t)uppercase,
            (struct container_t){ .items=str, .size=sizeof(str), .itemsize=sizeof(char) }
        );
        for (size_t i = 0; i < res.size / res.itemsize; ++i)
            printf("%c", ((char*)res.items)[i]); // C0OL_
        printf("\n");
    }
}
