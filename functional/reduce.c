#include "functional.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>

int add(int a, int b)
{
    return a + b;
}

char* concat(const char* a, char b)
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
        reducer_t reducer = (reducer_t)add;
        int arr[] = { 1, 2, 3 };
        struct container_t container = {arr, sizeof(arr), sizeof(int)};
        generic_t res = reduce(reducer, 0, container);
        printf("%ld\n", (uintptr_t)res); // 6
    }
    
    {
        reducer_t reducer = (reducer_t)concat;
        char str[] = "ommy";
        struct container_t container = {str, sizeof(str) - sizeof(char), sizeof(char)};
        generic_t res = reduce(reducer, "T", container);
        printf("%s\n", (char*)res); // Tommy
    }

    {
        reducer_t reducer = (reducer_t)or;
        bool arr[] = { false, true, true };
        struct container_t container = {arr, sizeof(arr), sizeof(bool)};
        generic_t res = reduce(reducer, false, container);
        printf("%s\n", (uintptr_t)res? "true" : "false");
    }
}
