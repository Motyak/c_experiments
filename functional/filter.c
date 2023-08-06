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
        predicate_t predicate = (predicate_t)is_odd;
        int arr[] = { 1, 2, 3, 4 };
        struct container_t input = {arr, sizeof(arr), sizeof(int)};
        struct container_t res = filter(predicate, input);
        for (size_t i = 0; i < res.size / res.itemsize; ++i)
        {
            printf("%d", ((int*)res.items)[i]);
        }
        printf("\n");
    }

    {
        predicate_t predicate = (predicate_t)is_lowercase;
        char str[] = "Asleep_";
        struct container_t input = {str, sizeof(str), sizeof(char)};
        struct container_t res = filter(predicate, input);
        for (size_t i = 0; i < res.size / res.itemsize; ++i)
        {
            printf("%c", ((char*)res.items)[i]);
        }
        printf("\n");

        predicate = (predicate_t)is_odd;
        res = filter(predicate, res);
        for (size_t i = 0; i < res.size / res.itemsize; ++i)
        {
            printf("%c", ((char*)res.items)[i]);
        }
        printf("\n");
    }
}
