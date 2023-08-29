#include "reduce.h"

#include <assert.h>
#include <string.h>

typedef generic_t (*function_t)(generic_t);

// global variable used by add function, set by setup_add_function function
static _Thread_local function_t g_add__fn = NULL;

// should be a lambda because of the fn bounded parameter
// inject the function as a global variable that will be accessed by the add function, as if it was lexically bound through a closure (except we live in c world)
static void setup_add_function(function_t fn)
{
    g_add__fn = fn;
}

struct container_t* add(struct container_t* list, generic_t curr)
{
    struct container_t* res = malloc(sizeof(struct container_t));
    size_t new_size = list->size + list->itemsize;
    char* new_items = malloc(new_size);
    memcpy(new_items, list->items, list->size);
    assert(g_add__fn != NULL);
    function_t fn = g_add__fn;
    *(new_items + list->size) = fn(curr);
    res->items = new_items;
    res->size = new_size;
    res->itemsize = list->itemsize;
    return res;
}

struct container_t map(function_t fn, struct container_t input)
{
    setup_add_function(fn);
    struct container_t* acc = malloc(sizeof(struct container_t));
    *acc = (struct container_t){ .items=NULL, .size=0, .itemsize=input.itemsize };
    return *(struct container_t*)reduce(
        /*reducer=*/(reducer_t)add,
        /*initial=*/acc,
        /*input=*/input
    );
}

