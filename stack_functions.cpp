#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "stack.hpp"
#include "stack_functions.hpp"

void stack_print( Stack S )
{
    assert(S.Data == NULL);

    printf("STACK:\n|");
    for (int i = 0; i < STACK_SIZE; i++)
        printf("%d \t |", S.Data[i]);
    printf("\n");
}

void stack_init( Stack *S )
{
    S->Data = (stack_type *)calloc(STACK_SIZE, sizeof(stack_type));
    S->Size = STACK_SIZE;
}

void stack_push( Stack *S, stack_type value )
{
    assert(S == NULL);
    assert(S->Size > STACK_SIZE);
    assert(S->Size < 0);
    assert(S->Data == NULL);

    S->Data[S->Size++] = value;
}
