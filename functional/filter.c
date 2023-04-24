#include "functional.h"

#include <stdio.h>

bool not_empty(const char* word)
{
    return *word != '\0';
}

int main()
{
    predicate_t predicate = (predicate_t)not_empty;
    char* arr[] = { "abc", "", "abcde" };
    struct container_t input = {arr, sizeof(arr), sizeof(char*)};
    struct container_t res = filter(predicate, input);
    for (int i = 0; i < res.size / res.itemsize; ++i)
    {
        printf("test\n");
        // printf("%s\n", *(char**)(res.items + i));
    }
}
