#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TRACE(prefix, msg, ...) \
    { \
        char formatted_msg[4096]; \
        sprintf(formatted_msg, msg, ##__VA_ARGS__); \
        fprintf(stderr, "%s: %s\n\t-> (%s:%d)\n", prefix, formatted_msg, __FILE__, __LINE__); \
    }

#define ERROR(msg, ...) \
    TRACE("ERR", msg, ##__VA_ARGS__); \
    exit(1);

#define WARNING(msg, ...) \
    TRACE("WARN", msg, ##__VA_ARGS__);

void allocate(int** variable) {
    if (*variable) {
        free(*variable); // avoids memory leaks (losing possibility to free memory)
    }
    *variable = malloc(sizeof(int));
}

void unallocate(int** variable) {
    if (!*variable) {
        WARNING("Tried to unallocate an already unallocated variable");
        return;
    }
    free(*variable);
    *variable = NULL; // avoids dangling pointer (pointing to freed data)
}

void assign(int* variable, int value) {
    if (!variable) {
        ERROR("Could not assign value %d to unallocated variable", value);
    }
    *variable = value;
}

void print(const int* variable) {
    printf("%p", variable);
    if (variable) {
        printf(";%d", *variable);
    }
    printf("\n\n");
}

int main()
{
    int* number = NULL;

    printf("allocate \n");
    allocate(&number);
    print(number);

    printf("assign \n");
    assign(number, 10);
    print(number);

    printf("unallocate \n");
    unallocate(&number);
    print(number);
}

