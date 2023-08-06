#include "reduce.h"

#include <stdbool.h>
#include <assert.h>
#include <string.h>

#include <stdio.h> // debug

typedef bool (*predicate_t)(generic_t);

// global variable used by update function, set by setup_update_function function
static predicate_t g_update__predicate = NULL;

// should be a lambda because of the pred bounded parameter
// inject the predicate as a global variable that will be accessed by the update function, as if it was lexically bound through a closure (except we live in c world)
static void setup_update_function(predicate_t pred)
{
    g_update__predicate = pred;
}

struct container_t* update(struct container_t* list, generic_t curr)
{
    struct container_t* res = malloc(sizeof(struct container_t));
    *res = *list;
    
    assert(g_update__predicate != NULL);
    predicate_t pred = g_update__predicate;
    if (pred(curr))
    {
        size_t new_size = list->size + list->itemsize;
        void** new_items = malloc(new_size);
        memcpy(new_items, list->items, list->size);
        // this statement assumes item size of 8 bytes (void*), i'd rather use list->itemsize to allow int instead of llong
        *(new_items + list->size / list->itemsize) = curr;
        res->items = new_items;
        res->size = new_size;
        res->itemsize = list->itemsize;
    }
    
    return res;
}

struct container_t filter(predicate_t pred, struct container_t input)
{
    reducer_t reducer = (reducer_t)update;
    setup_update_function(pred);
    struct container_t* acc = malloc(sizeof(struct container_t));
    assert(acc != NULL); // malloc can fail
    *acc = (struct container_t){NULL, 0, input.itemsize};
    return *(struct container_t*)reduce(reducer, acc, input);



    // struct container_t acc = {NULL, };
    // size_t length = container.size / container.itemsize;
    // void** curr = NULL;
    // for (int i = 0; i < length; ++i)
    // {
    //     curr = container.items + i * container.itemsize;
    //     acc = reducer(acc, *curr);
    // }
    // return acc;


    // reducer_t reducer = (reducer_t)update;
    // struct container_t empty_container = {NULL, 0, input.itemsize};
    // generic_t accumulator = (generic_t)&empty_container;
    // struct container_t* res = reduce(reducer, accumulator, input);
    // return *res;
}


