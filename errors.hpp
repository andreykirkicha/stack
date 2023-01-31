#ifndef ERRORS_HPP
#define ERRORS_HPP

#include "stack.hpp"

#define STACK_CHECK_CONDITIONS(condition, error)\
        S->Errors |= (condition) ? (error) : 0

#define STACK_VERIFY(s) errors_print(s, __LINE__, __func__, __FILE__)

enum ERRORS {
    ERR_S_NULL =                    1 << 0,
    ERR_S_DATA_NULL =               1 << 1,
    ERR_NEGATIVE_S_TOP =            1 << 2,
    ERR_S_TOP_HIGHER_STACK_SIZE =   1 << 3
};

enum STATUS {
    SESSION_JUST_STARTED, SESSION_CONTINUES
};

int errors_check( Stack *S );
void errors_print( Stack S, int line, const char *func, const char *file );

#endif
