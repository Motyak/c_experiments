#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "generic_types.h"

#define add(a, b) add(float_from(a), float_from(b))
float (add)(float a, float b)
{
    return a + b;
}

int main()
{
    float a = 3.0f;
    float b = 4.0f;

    Float x = Float_from(a);
    Float y = Float_from(&b);
    printf("%f %f\n", x.scalar, *y.ptr);

    printf("%f\n", add(a, b));
    printf("%f\n", add(&a, &b));
}
