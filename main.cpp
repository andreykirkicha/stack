#include <stdio.h>
#include <stdlib.h>

#include "stack.hpp"
#include "stack_functions.hpp"

int main()
{
    struct Stack S;

    stack_init(&S);
    stack_print(S);
    /*
    stack_push(&S, 10);
    stack_print(S);

    stack_push(&S, 20);
    stack_print(S);

    stack_push(&S, 30);
    stack_print(S);

    int x = stack_pop(&S);
    int y = stack_pop(&S);
    int z = stack_pop(&S);

    stack_delete(&S);
*/
    return 0;
}
