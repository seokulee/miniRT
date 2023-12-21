#include "error.h"

void    err_put_str(char *str, int exit_code)
{
    printf("%s\n", str);
    exit(exit_code);
}
