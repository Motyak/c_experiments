
#include <stdio.h>

#define len(arr) (sizeof(arr) / sizeof(arr[0]))

int sum(int* nbs_list, size_t list_length)
{
    int res = 0;

    for (size_t i = 0; i < list_length; ++i)
        res += nbs_list[i];

    return res;
}

int main()
{
    int input[] = { 1, 2, 3 };
    int res = sum(input, len(input));

    printf("%d\n", res);
}
