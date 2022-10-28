#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "stack.hpp"
#include "stack_functions.hpp"

void stack_print( struct Stack S )
{
    assert(S.Data != NULL);

    printf("STACK:\n|");
    for (size_t i = 0; i < STACK_SIZE; i++)
        printf(" %d |", S.Data[i]);
    printf("\n");
}

void stack_init( struct Stack *S )
{
    S->Data = (stack_type *)calloc(STACK_SIZE, sizeof(stack_type));
    S->Size = STACK_SIZE;
    S->Top = 0;
}

void stack_push( struct Stack *S, stack_type value )
{
    assert(S != NULL);
    assert(S->Size <= STACK_SIZE);
    assert(S->Size >= 0);
    assert(S->Data != NULL);
    assert(S->Top >=0);
    assert(S->Top <= STACK_SIZE);

    S->Data[S->Size++] = value;
}
