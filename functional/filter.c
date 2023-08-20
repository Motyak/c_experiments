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
            printf("%d ", ((int*)res.items)[i]); // 1 3
        }
        printf("\n");
    }

    {
        char str[] = "Asleep_";
        struct container_t input = {str, sizeof(str), sizeof(char)};
        predicate_t pred = (predicate_t)is_lowercase;
        filterer_t filterer = build_filterer(pred);

        struct container_t res = filterer(input);
        for (size_t i = 0; i < res.size / res.itemsize; ++i)
        {
            printf("%c", ((char*)res.items)[i]); // sleep
        }
        printf("\n");
    }

    {
        char str[] = "Asleep_";
        struct container_t input = {str, sizeof(str), sizeof(char)};
        predicate_t pred_a = (predicate_t)is_lowercase;
        predicate_t pred_b = (predicate_t)is_odd;
        filterer_t filterer = build_filterer(pred_a, pred_b);

        struct container_t res = filterer(input);
        for (size_t i = 0; i < res.size / res.itemsize; ++i)
        {
            printf("%c", ((char*)res.items)[i]); // see
        }
        printf("\n");
    }
}
