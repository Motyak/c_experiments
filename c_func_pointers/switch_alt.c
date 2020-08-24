






#include "stdio.h"

enum Operation
{
    ADD,
    SUB,
    MUL
};

int add(int x, int y) { return x + y; }
int sub(int x, int y) { return x - y; }
int mul(int x, int y) { return x * y; }

int (*op[4])(int, int) = { add, sub, mul };

int main()
{
    printf("%d\n", op[MUL](2, 3));
}














