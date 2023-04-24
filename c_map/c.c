#include <stdio.h>
#include <stdlib.h>

enum Type { NAME, NICKNAME };

int main()
{

    char str1[] = "tommy";
    char* str2 = "motyak";

    char** map = malloc(2 * sizeof(char*));
    *map = str1;
    *(map + 1) = str2;

    printf("%s,%s\n", map[NAME], map[NICKNAME]);

    free(map);
}
