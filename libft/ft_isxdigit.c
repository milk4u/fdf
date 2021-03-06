/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:28:14 by apisotsk          #+#    #+#             */
/*   Updated: 2016/11/21 16:42:13 by apisotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isxdigit(int c)
{
	return (((c >= '0') && (c <= '9')) || ((c >= 'a') && (c <= 'f'))
			|| ((c >= 'A') && (c <= 'F')));
}
