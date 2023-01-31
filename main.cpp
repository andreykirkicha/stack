#include <stdio.h>
#include <stdlib.h>

#include "stack.hpp"
#include "stack_functions.hpp"
#include "errors.hpp"

int session_status = SESSION_JUST_STARTED;

int main()
{
    struct Stack S;

    stack_init(&S);
    printf("INIT\n");
    stack_print(S);

    stack_push(&S, 10);
    printf("PUSH 10\n");
    stack_print(S);

    stack_push(&S, 20);
    printf("PUSH 20\n");
    stack_print(S);

    stack_type x = stack_pop(&S);
    printf("POP: %d\n", x);
    stack_print(S);

    stack_type y = stack_pop(&S);
    printf("POP: %d\n", y);
    stack_print(S);

    stack_delete(&S);
    printf("DELETE\n");
    stack_print(S);

    return 0;
}
