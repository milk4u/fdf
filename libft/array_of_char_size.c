#include "libft.h"

size_t	arr_size(char **arr)
{
	size_t		size;

	size = 0;
	if (arr && *arr)
		while (arr[size])
			size++;
	return (size);
}