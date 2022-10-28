#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "stack.hpp"
#include "stack_functions.hpp"

void stack_print( Stack S )
{
    assert(S.Data != NULL);

    printf("STACK:\n|");
    for (size_t i = 0; i < STACK_SIZE; i++)
        printf(" %d |", S.Data[i]);
    printf("\n\n");
}

void stack_init( Stack *S )
{
    S->Data = (stack_type *)calloc(STACK_SIZE, sizeof(stack_type));
    S->Top = 0;
}

void stack_push( Stack *S, stack_type value )
{
    assert(S != NULL);
    assert(S->Data != NULL);
    assert(S->Top >=0);
    assert(S->Top <= STACK_SIZE);

    S->Data[S->Top++] = value;
}

stack_type stack_pop( Stack *S )
{
    stack_type value = 0;

    assert(S != NULL);
    assert(S->Data != NULL);
    assert(S->Top >=0);
    assert(S->Top <= STACK_SIZE);

    value = S->Data[S->Top-- - 1];
    S->Data[S->Top] = 0;

    return value;
}

void stack_delete( Stack *S )
{
    assert(S != NULL);
    assert(S->Data != NULL);
    assert(S->Top >=0);
    assert(S->Top <= STACK_SIZE);

    while (S->Top-- != 0)
        stack_pop(S);

    free(S->Data);
}
