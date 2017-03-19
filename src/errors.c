#include "../includes/errors.h"

void            p_error(const char *file, const char *func, int l, int errno)
{
    char        *err;

    if (!(err = ft_strnew(BUFF_SIZE_ERR)))
        perror("Error 0. Can`t allocate memory in function p_error, from file src/errors.c, at line #8");
    else 
    {   if (errno == 1)
            ft_strlcat(err, "Error 1. Can`t allocate memory in function ", BUFF_SIZE_ERR);
        else if (errno == 2)
            ft_strlcat(err, "Error 2. Can`t read data from file in function ", BUFF_SIZE_ERR);
        ft_strlcat(err, func, (size_t)BUFF_SIZE_ERR);
        ft_strlcat(err, ", from file ", (size_t)BUFF_SIZE_ERR);
        ft_strlcat(err, file, BUFF_SIZE_ERR);
        ft_strlcat(err, ", at line #" ,BUFF_SIZE_ERR);
        ft_strlcat(err, ft_itoa(l), BUFF_SIZE_ERR);
	    perror(err);
    }
	exit(EXIT_FAILURE);
} 