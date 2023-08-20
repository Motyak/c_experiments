#include "Vector.h"

#include <stdlib.h>
#include <assert.h>
#include <stdio.h> //debug

#define VEC_INIT_CAPACITY 1

struct Vector* Vector_new()
{
    struct Vector* new = malloc(sizeof(struct Vector));
    new->arr = calloc(VEC_INIT_CAPACITY, sizeof(void*));
    assert(new->arr != NULL);
    new->capacity = VEC_INIT_CAPACITY;
    new->size = 0;

    return new;
}

void Vector_delete(struct Vector* vec)
{
    if (vec == NULL)
        return;
    if (vec->arr != NULL)
        free(vec->arr);
    free(vec);
    vec = NULL;
}

void Vector_push_back(struct Vector* self, void* new_item)
{
    if (self->size == self->capacity)
    {
        size_t new_capacity = self->capacity * 2;
        assert(new_capacity > self->capacity);
        self->arr = realloc(self->arr, sizeof(void*) * new_capacity);
        assert(self->arr != NULL);
        printf("capacity from %ld to %ld\n", self->capacity, new_capacity);
        self->capacity = new_capacity;
    }
    // void** arr = self->arr;
    // *(arr + self->size++) = new_item;
    ((void**)self->arr)[self->size++] = new_item;
}

void* Vector_get(const struct Vector* self, size_t i)
{
    assert(i < self->size);
    return ((void**)self->arr)[i];
}
