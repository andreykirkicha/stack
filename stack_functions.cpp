#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "stack.hpp"
#include "stack_functions.hpp"
#include "errors.hpp"

void stack_print( Stack S )
{
    STACK_VERIFY(S);

    printf("STACK:\n|");
    for (size_t i = 0; i < S.Size; i++)
        printf(" %d |", S.Data[i]);
    printf("\n\n");
}

void stack_init( Stack *S )
{
    S->Size = STACK_SIZE;
    S->Data = (stack_type *)calloc(S->Size, sizeof(stack_type));
    S->Top = 0;
    S->Errors = 0;
}

void stack_push( Stack *S, stack_type value )
{
    STACK_VERIFY(*S);

    S->Data[S->Top++] = value;
}

stack_type stack_pop( Stack *S )
{
    STACK_VERIFY(*S);

    stack_type value = 0;

    value = S->Data[S->Top-- - 1];
    S->Data[S->Top] = 0;

    return value;
}

void stack_delete( Stack *S )
{
    STACK_VERIFY(*S);

    while (S->Top != 0)
    {
        stack_pop(S);
        S->Top--;
    }

    free(S->Data);
}
