/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 10:23:24 by apisotsk          #+#    #+#             */
/*   Updated: 2016/11/28 10:23:26 by apisotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_space(int c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char		*ft_strtrim(char const *s)
{
	char	*cp;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (is_space(*s) && len != 0)
	{
		s++;
		len--;
	}
	len = ft_strlen(s);
	while (is_space(s[len - 1]) && len != 0)
		len--;
	if (!(cp = ft_strnew(len)))
		return (NULL);
	ft_strncpy(cp, s, len);
	return (cp);
}
