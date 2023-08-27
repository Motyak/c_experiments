#include "filter.h"

#include <stdio.h>

bool is_odd(int a)
{
    return a & 1;
}

bool is_lowercase(char c)
{
    return 97 <= c && c <= 122;
}

int main()
{
    {
        int arr[] = { 1, 2, 3, 4 };
        struct container_t res = filter(
            /*predicate=*/(predicate_t)is_odd,
            /*input=*/(struct container_t){ .items=arr, .size=sizeof(arr), .itemsize=sizeof(int) }
        );
        for (size_t i = 0; i < res.size / res.itemsize; ++i)
            printf("%d ", ((int*)res.items)[i]); // 1 3 
        printf("\n");
    }

    char str[] = "Asleep_";
    struct container_t input = { .items=str, .size=sizeof(str)-sizeof(char), .itemsize=sizeof(char) };

    {
        filterer_t filterer = build_filterer((predicate_t)is_lowercase);
        struct container_t res = filterer(input);
        for (size_t i = 0; i < res.size / res.itemsize; ++i)
            printf("%c", ((char*)res.items)[i]); // sleep
        printf("\n");
    }

    {
        filterer_t filterer = build_filterer(
            (predicate_t)is_lowercase,
            (predicate_t)is_odd
        );
        struct container_t res = filterer(input);
        for (size_t i = 0; i < res.size / res.itemsize; ++i)
            printf("%c", ((char*)res.items)[i]); // see
        printf("\n");
    }
}
