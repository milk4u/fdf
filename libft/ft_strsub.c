/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:06:05 by apisotsk          #+#    #+#             */
/*   Updated: 2016/11/22 15:06:56 by apisotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (s == NULL || len == 0)
		return (NULL);
	if (ft_strlen(s) < start)
		return (NULL);
	if (!(new = ft_strnew(len)))
		return (NULL);
	i = -1;
	while (++i < len && s[i])
		new[i] = s[start + i];
	return (new);
}
