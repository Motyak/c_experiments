#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "generic_types.h"
#include "reduce.h"

#define add(a, b) *add(Ptr_from(a), Ptr_from(b))
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
    printf("%f %f\n", x.scalar, *y.ptr); // 3.000000 4.000000

    /* addition passing scalar values */
    printf("%f\n", add(a, b)); // 7.000000
    /* addition passing one pointer and one literal */
    printf("%f\n", add(&a, -3.0f)); // 0.000000

    /* addition using reduce, passing pointers */
    float* input[] = {&a, &b, Ptr_from(5.0f)};
    float* res = reduce(
        /*reducer=*/(reducer_t)add,
        /*initial=*/(generic_t)Ptr_from(0.0f),
        /*input=*/Container_of(input)
    );
    printf("%f\n", *res); // 12.000000
}
