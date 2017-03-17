/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:07:25 by apisotsk          #+#    #+#             */
/*   Updated: 2016/11/22 15:04:49 by apisotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *src, int c)
{
	size_t	lenght;

	lenght = ft_strlen(src);
	if (c == 0)
		return ((char*)&src[lenght]);
	while (lenght > 0)
		if (src[--lenght] == c)
			return ((char*)&src[lenght]);
	return (NULL);
}
