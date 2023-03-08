#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define len(x) (sizeof(x)/sizeof(x[0]))

struct container_t
{
    void* items;
    size_t size;
    size_t itemsize;
};

typedef void* generic_t;

/* returns the updated accumulator based on current */
typedef generic_t (*reducer_t)(generic_t accumulator, generic_t current);

generic_t reduce(reducer_t reducer, generic_t initial, struct container_t container)
{
    generic_t acc = initial;
    size_t length = container.size / container.itemsize;
    void** curr = NULL;
    for (int i = 0; i < length; ++i)
    {
        curr = container.items + i * container.itemsize;
        printf("DEBUG: %d\n", acc);
        printf("DEBUG: %d\n", *curr);
        acc = reducer(acc, *curr);
    }
    return acc;
}

const int add(const int a, const int b)
{
    return a + b;
}

// const char* concat(const char* a, const char* b)
// {
//     char res[strlen(a) + strlen(b)];
//     strcpy(res, a);
//     strcat(res, b);
//     return res;
// }


int main()
{
    {
        reducer_t reducer = add;
        int arr[] = { 1, 2, 3 };
        struct container_t container = {arr, sizeof(arr), sizeof(int)};
        generic_t res = reduce(reducer, 0, container);
        // printf("%d\n", res);
    }
    
    // {
    //     reducer_t reducer = concat;
    //     char str[] = "ommy";
    //     // struct container_t container = {str, sizeof(str), sizeof(char)};
    //     struct container_t container = {str, sizeof(str) - sizeof('\0'), sizeof(char)};
    //     generic_t res = reduce(reducer, "T", container);
    //     printf("%s\n", res);
    // }
}
