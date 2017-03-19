/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:02:48 by apisotsk          #+#    #+#             */
/*   Updated: 2016/11/24 20:37:53 by apisotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	i;

	dstlen = ft_strlen(dst) < size ? ft_strlen(dst) : size;
	if (size - dstlen == 0)
		return (size + ft_strlen(src));
	i = -1;
	while ((dstlen + ++i < size - 1) && (src[i]))
		dst[dstlen + i] = src[i];
	dst[dstlen + i] = '\0';
	return (dstlen + ft_strlen(src));
}
