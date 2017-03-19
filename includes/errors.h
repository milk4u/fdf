#ifndef ERRORS_H
# define ERRORS_H
# define MALLOC_ERR 1
# define FILE_ERR 2
# define BUFF_SIZE_ERR 160
#include <stdio.h>
#include <stdlib.h>
#include "./libft.h"

void            p_error(const char *file, const char *func, int l, int errno);

#endif