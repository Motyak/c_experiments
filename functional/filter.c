#include "filter.h"

#include <stdio.h>

// bool not_empty(const char* word)
// {
//     return *word != '\0';
// }

// int main()
// {
//     predicate_t predicate = (predicate_t)not_empty;
//     char* arr[] = { "abc", "", "abcde" };
//     struct container_t input = {arr, sizeof(arr), sizeof(char*)};
//     struct container_t res = filter(predicate, input);
//     for (size_t i = 0; i < res.size / res.itemsize; ++i)
//     {
//         // printf("test\n");
//         printf("%s\n", ((char**)res.items)[i]);
//     }
// }

bool not_zero(int a)
{
    return a != 0;
}

int main()
{
    predicate_t pred = (predicate_t)not_zero;
    setup_update_function(pred);
    
    struct container_t* init = malloc(sizeof(struct container_t));
    *init = (struct container_t){NULL, 0, sizeof(int)};
    int list[] = {1, 0, 2, 3};
    struct container_t* res = malloc(sizeof(struct container_t));
    *res = *init;
    for (int i = 0; i < 4; ++i)
    {
        printf("%d    ", list[i]);
        res = update(res, list[i]);
        printf("%d %d %d\n", ((int*)res->items)[0], ((int*)res->items)[1], ((int*)res->items)[2]);
    }
    printf("%d %d %d\n", ((int*)res->items)[0], ((int*)res->items)[1], ((int*)res->items)[2]);
}


