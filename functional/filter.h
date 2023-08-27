#include "reduce.h"

#include <stdbool.h>
#include <assert.h>
#include <stdarg.h>
#include <string.h>

#include <stdio.h> // debug

typedef bool (*predicate_t)(generic_t);
typedef struct container_t (*filterer_t)(struct container_t input);

#define FILTERER_MAX_LENGTH 10
static _Thread_local predicate_t* g_filterer = NULL;
static _Thread_local int g_filterer_length = 0;

// global variable used by update function, set by setup_update_function function
static _Thread_local predicate_t g_update__predicate = NULL;

// should be a lambda because of the pred bounded parameter
// inject the predicate as a global variable that will be accessed by the update function, as if it was lexically bound through a closure (except we live in c world)
static void setup_update_function(predicate_t pred)
{
    g_update__predicate = pred;
}

static struct container_t* update(struct container_t* list, generic_t curr)
{
    struct container_t* res = malloc(sizeof(struct container_t));
    *res = *list;
    
    assert(g_update__predicate != NULL);
    predicate_t pred = g_update__predicate;
    if (pred(curr))
    {
        size_t new_size = list->size + list->itemsize;
        char* new_items = malloc(new_size);
        memcpy(new_items, list->items, list->size);
        *(new_items + list->size) = curr;
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
    *acc = (struct container_t){ .items=NULL, .size=0, .itemsize=input.itemsize };
    return *(struct container_t*)reduce(reducer, acc, input);
}

// temporary hack to bypass pred check in update (force update)
static bool always_true(generic_t _)
{
    return true;
}

static struct container_t execute(struct container_t input)
{
    assert(g_filterer != NULL);
    // hack to force upcoming updates
    setup_update_function(always_true);

    struct container_t* res = malloc(sizeof(struct container_t));
    *res = (struct container_t){ .items=NULL, .size=0, .itemsize=input.itemsize };
    size_t length = input.size / input.itemsize;
    void** curr = NULL;
    for (size_t i = 0; i < length; ++i)
    {
        curr = input.items + i * input.itemsize;
        bool acc = true;
        for (int i = 0; i < g_filterer_length; ++i)
            acc &= g_filterer[i](*curr);

        // if all predicates returned true
        if (acc)
            res = (struct container_t*)update(res, *curr);
    }

    return *res;
}

#define build_filterer(...) build_filterer(__VA_ARGS__, NULL);
filterer_t (build_filterer)(predicate_t pred_a, predicate_t pred_b, ...)
{
    if (g_filterer == NULL)
        g_filterer = malloc(sizeof(predicate_t) * FILTERER_MAX_LENGTH);
    g_filterer_length = 0;
    
    va_list args;
    va_start(args, pred_b);
    g_filterer[g_filterer_length++] = pred_a;
    predicate_t curr_pred = pred_b;
    while (curr_pred != NULL)
    {
        assert(g_filterer_length <= FILTERER_MAX_LENGTH);
        g_filterer[g_filterer_length++] = curr_pred;
        curr_pred = va_arg(args, predicate_t);
    }
    va_end(args);

    return execute;
}
