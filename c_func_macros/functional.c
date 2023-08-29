#include <stdio.h>

#define len(arr) (sizeof(arr) / sizeof(arr[0]))

static int sum__sum_iter(const int* nbs_list, size_t list_length, size_t i, int res)
{
    return (i == list_length)?
        res
        : sum__sum_iter(nbs_list, list_length, i + 1, res + nbs_list[i]);
}

int sum(const int* nbs_list, size_t list_length)
{
    return sum__sum_iter(nbs_list, list_length, 0, 0);
}

int main()
{
    #define square(x) (x * x)
    #define input (int[]){ square(3), square(4) }
    #define res sum(input, len(input))

    printf("%d\n", res);

    #undef square
    #undef input
    #undef res
}
