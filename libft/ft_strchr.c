/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:50:36 by apisotsk          #+#    #+#             */
/*   Updated: 2016/11/24 20:36:13 by apisotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	if (!src)
		return (NULL);
	if (c == 0)
		return ((char*)&src[ft_strlen(src)]);
	while (*src)
	{
		if (*src == c)
			return ((char*)src);
		src++;
	}
	return (NULL);
}
