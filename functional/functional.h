#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include <stdio.h> // debug

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
    for (int i = 0; i < length; ++i)
    {
        curr = input.items + i * input.itemsize;
        acc = reducer(acc, *curr);
    }
    return acc;
}

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
    assert(g_update__predicate != NULL); // prevent potential undefined behavior
    predicate_t pred = g_update__predicate;
    if (pred(curr))
    {
        void** new_elements = realloc(list, list->size + list->itemsize);
        assert(new_elements != NULL); // realloc can fail
        *(new_elements + list->size) = curr;
        list->items = new_elements;
        list->size += list->itemsize;
    }
    return list;
}

struct container_t filter(predicate_t pred, struct container_t input)
{
    reducer_t reducer = (reducer_t)update;
    setup_update_function(pred);
    struct container_t* acc = malloc(sizeof(struct container_t));
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


