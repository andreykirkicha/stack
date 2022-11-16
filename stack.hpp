#ifndef STACK_HPP
#define STACK_HPP

#include <stdio.h>

const int STACK_SIZE = 10;

typedef int stack_type;

struct Stack {
    stack_type *Data;
    size_t Top;
    size_t Size;
    size_t Errors;
};

#endif
