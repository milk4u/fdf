/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:06:04 by apisotsk          #+#    #+#             */
/*   Updated: 2016/11/22 14:06:06 by apisotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new;

	if (!s || !f)
		return (NULL);
	if (!(new = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = -1;
	while (s[++i])
		new[i] = f(i, s[i]);
	return (new);
}
