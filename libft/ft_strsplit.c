/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 10:18:15 by apisotsk          #+#    #+#             */
/*   Updated: 2016/11/30 16:04:00 by apisotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cwords(const char *s, char sep)
{
	size_t		cwords;

	cwords = 0;
	while (*s)
	{
		if (*s != sep)
		{
			cwords++;
			while (*s != sep && *s)
				s++;
			if (*s == '\0')
				break ;
		}
		s++;
	}
	return (cwords);
}

static size_t	ft_clenght(const char *s, char sep)
{
	size_t		clenght;

	clenght = 0;
	while (*s != sep && *s)
	{
		clenght++;
		s++;
	}
	return (clenght);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**ans;
	size_t		wl;
	size_t		i;

	if (!s)
		return (NULL);
	if (!(ans = (char**)malloc(sizeof(char*) * (ft_cwords(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			wl = ft_clenght(s, c);
			ans[i] = ft_strnew(wl);
			ft_strncpy(ans[i++], s, wl);
			s += wl;
		}
		if (*s == '\0')
			break ;
		s++;
	}
	ans[i] = NULL;
	return (ans);
}
