#include "errors.hpp"

const char *LOG_FILE_NAME = "log.txt";
const char *ERRORS_DESCR[] = {"stack address is NULL",
                            "stack data pointer is NULL",
                            "stack top has negative value",
                            "stack top is higher than possible",
                            "stack was not initialized"};

int errors_check( Stack *S )
{
    S->Errors = 0;

    STACK_CHECK_CONDITIONS(S == NULL, ERR_S_NULL);
    STACK_CHECK_CONDITIONS(S->Data == NULL, ERR_S_DATA_NULL);
    STACK_CHECK_CONDITIONS(S->Top < 0, ERR_NEGATIVE_S_TOP);
    STACK_CHECK_CONDITIONS(S->Top > S->Size, ERR_S_TOP_HIGHER_STACK_SIZE);

    return S->Errors;
}

void errors_print( Stack S, int line, const char *func, const char *file )
{
    FILE *log_file = NULL;
    int error_emerg = 0;

    log_file = fopen(LOG_FILE_NAME, "a");

    fprintf(log_file, "=========================================================================\n"
            "%s() in %s (line %d)\n\n", func, file, line);

    errors_check(&S);

    for (int i = 0; S.Errors > 0; i++, S.Errors /= 2)
    {
        if ((S.Errors & (1 << i)) >> i)
        {
            fprintf(log_file, "STATUS: \t error: \t %s\n\n", ERRORS_DESCR[i]);
            error_emerg = 1;
        }
    }

    if (error_emerg == 0)
        fprintf(log_file, "STATUS: \t no errors\n\n\n");

    fclose(log_file);
}
