#ifndef STACK_HPP
#define STACK_HPP

typedef int stack_type;

const int STACK_SIZE = 10;

struct Stack {
    stack_type *Data;
    size_t Size;
};

#endif
