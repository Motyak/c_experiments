#include "stdio.h"

void foreach(void* elements, int length, size_t size, void (*fn)(void*))
{
    for(int i = 0 ; i < length ; ++i)
        fn(elements + i * size);
}

void square(int* n){ *n *= *n; }
void upper(char* c) { *c -= 32; }

// gcc -o foreach foreach.c
int main()
{
    int arr[] = { 2, 3, 4 };
    int arrLength = sizeof(arr) / sizeof(int);

    char str[] = "hello";
    int strLength = sizeof(str) / sizeof(char);

    foreach(arr, arrLength, sizeof(int), square);
    foreach(str, strLength - 1, sizeof(char), upper);

    for(int i = 0 ; i < arrLength ; ++i)
        printf("%d\n", arr[i]);
    for(int i = 0 ; i < strLength - 1 ; ++i)
        printf("%c", str[i]);
    printf("\n");
}
