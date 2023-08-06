/* 
 * We can't dynamically build functions from functions in C (no lambda),..
 * .. normally we would have defined `pipe` function using reduce to compose functions..
 * .. one by one into a pipeline.
*/

#include "reduce.h"

#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>

typedef generic_t (*function_t)(generic_t);
typedef generic_t (*pipeline_t)(generic_t);

#define PIPELINE_MAX_LENGTH 10
static function_t* g_pipeline = NULL;
static int g_pipeline_length = 0;


static generic_t execute(generic_t input)
{
    assert(g_pipeline != NULL);
    generic_t res = input;
    for (int i = 0; i < g_pipeline_length; ++i)
    {
        res = g_pipeline[i](res);
    }
    return res;
}

#define pipe(...) pipe(__VA_ARGS__, NULL);
pipeline_t (pipe)(function_t first, function_t second, ...)
{
    if (g_pipeline == NULL)
        g_pipeline = malloc(sizeof(function_t) * PIPELINE_MAX_LENGTH);
    g_pipeline_length = 0;
    
    va_list args;
    va_start(args, second);
    g_pipeline[g_pipeline_length++] = first;
    function_t curr_func = second;
    while (curr_func != NULL)
    {
        assert(g_pipeline_length <= PIPELINE_MAX_LENGTH);
        g_pipeline[g_pipeline_length++] = curr_func;
        curr_func = va_arg(args, function_t);
    }
    va_end(args);

    return execute;
}
