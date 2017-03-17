/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:20:50 by apisotsk          #+#    #+#             */
/*   Updated: 2016/11/22 15:10:27 by apisotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *m1, const void *m2, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		if (((unsigned char*)m1)[i] != ((unsigned char*)m2)[i])
			return (((unsigned char*)m1)[i] - ((unsigned char*)m2)[i]);
	return (0);
}
