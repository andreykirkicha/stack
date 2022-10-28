#ifndef STACK_FUNCTIONS_HPP
#define STACK_FUNCTIONS_HPP

#include "stack.hpp"

void stack_print( Stack S );
void stack_init( Stack *S );
void stack_push( Stack *S, stack_type value );
stack_type stack_pop( Stack *S );
void stack_delete( Stack *S );

#endif
