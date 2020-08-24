

#include "stdio.h"

void foreach_char_apply(char* str, void (*fn)(char*))
{
    int i = 0;
    while(*(str + i) != '\0')
    {
        fn(str + i);
        ++i;
    }
}

void upper(char* c) { *c -= 32; }
void toA(char* c) { *c = 'A'; }

int main()
{
    // creates a string variable != 'char* = "hello"' that points to a constant string
    char str[] = "hello";

    foreach_char_apply(str, upper);
    printf("%s\n", str);

    foreach_char_apply(str, toA);
    printf("%s\n", str);
}














