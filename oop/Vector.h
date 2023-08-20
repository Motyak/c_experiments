#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

struct Vector
{
    void* arr;
    size_t size;
    size_t itemsize;
    size_t capacity;
};

struct Vector* Vector_new(size_t itemsize);
void Vector_delete(struct Vector* vec);

void Vector_push_back(struct Vector* self, void* new_item);
void* Vector_get(const struct Vector* self, size_t i);

#endif
