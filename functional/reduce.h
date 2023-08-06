#include <stdlib.h>

struct container_t
{
    void* items;
    size_t size;
    size_t itemsize;
};

typedef void* generic_t;
/* When multiple generic type parameters in a function signature BUT not necessarily the same */
typedef generic_t generic__A;
typedef generic_t generic__B;

/* returns the updated accumulator based on current */
typedef generic__A (*reducer_t)(generic__A accumulator, generic__B current);

generic_t reduce(reducer_t reducer, generic_t initial, struct container_t input)
{
    generic_t acc = initial;
    size_t length = input.size / input.itemsize;
    void** curr = NULL;
    for (size_t i = 0; i < length; ++i)
    {
        curr = input.items + i * input.itemsize;
        acc = reducer(acc, *curr);
    }
    return acc;
}
