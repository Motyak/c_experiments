#include "reduce.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int add(int a, int b)
{
    return a + b;
}

const char* concat(const char* a, char b)
{
    char input[2] = {b, '\0'};
    size_t length = strlen(a) + 1;
    char* res = malloc(length * sizeof(char));
    strcpy(res, a);
    strcat(res, input);
    return res;
}

bool or(bool a, bool b)
{
    return a | b;
}

int main()
{
    {
        int arr[] = { 1, 2, 3 };
        uintptr_t res = reduce(
            /*reducer=*/(reducer_t)add,
            /*initial=*/0,
            /*input=*/(struct container_t){ .items=arr, .size=sizeof(arr), .itemsize=sizeof(int) }
        );
        printf("%ld\n", res); // 6
    }

    {
        char str[] = "ommy";
        char* res = reduce(
            /*reducer=*/(reducer_t)concat,
            /*initial=*/"T",
            /*input=*/(struct container_t){ .items=str, .size=sizeof(str)-sizeof(char), .itemsize=sizeof(char) }
        );
        printf("%s\n", res); // Tommy
    }

    {
        bool arr[] = { false, true, true };
        uintptr_t res = reduce(
            /*reducer=*/(reducer_t)or,
            /*initial=*/false,
            /*input=*/(struct container_t){ .items=arr, .size=sizeof(arr), .itemsize=sizeof(bool)}
        );
        printf("%s\n", res? "true" : "false"); // true
    }
}
