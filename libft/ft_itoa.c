/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:15:41 by apisotsk          #+#    #+#             */
/*   Updated: 2016/11/28 17:32:02 by apisotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(int n)
{
	size_t		size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char		*arr;
	char		sign;
	size_t		i;

	sign = n >= 0 ? 0 : 1;
	if (!(arr = ft_strnew(get_size(n))))
		return (NULL);
	i = get_size(n);
	if (n == 0)
		arr[--i] = '0';
	while (n != 0)
	{
		if (n > 0)
			arr[--i] = n % 10 + '0';
		else if (n < 0)
			arr[--i] = '0' - (n % 10);
		n /= 10;
	}
	if (sign)
		arr[0] = '-';
	return (arr);
}
