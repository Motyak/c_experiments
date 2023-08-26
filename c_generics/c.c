#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "generic_types.h"
#include "reduce.h"

#define add(a, b) *add(floatptr_from(a), floatptr_from(b))
float* (add)(float* a, float* b)
{
    float* res = malloc(sizeof(float));
    *res = *a + *b;
    return res;
}

int main()
{
    float a = 3.0f;
    float b = 4.0f;

    /* union float type */
    Float x = Float_from(a);
    Float y = Float_from(&b);
    printf("%f %f\n", x.scalar, *y.ptr);

    /* addition passing scalar values */
    printf("%f\n", add(a, b));

    /* addition using reduce, passing pointers */
    float* input[3] = {&a, &b, floatptr_from(5.0f)};
    float* res = reduce(
        /*reducer=*/(reducer_t)add,
        /*initialization=*/(generic_t)floatptr_from(0.0f),
        /*input=*/(struct container_t){ .items=input, .size=sizeof(input) }
    );
    printf("%f\n", *res);
}
