#include "Vector.h"

#include <stdio.h>

int main()
{
    struct Vector* vec = Vector_new(sizeof(int));

    int val = 91;
    Vector_push_back(vec, &val);
    int* ret = Vector_get(vec, 0);
    printf("%d\n", *ret);

    int val2 = 333;
    Vector_push_back(vec, &val2);
    ret = Vector_get(vec, 1);
    printf("%d\n", *ret);

    Vector_push_back(vec, &val2);
    Vector_push_back(vec, &val2);

    Vector_push_back(vec, &val2);

    Vector_delete(vec);
    
}
