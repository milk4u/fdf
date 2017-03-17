/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 21:25:35 by apisotsk          #+#    #+#             */
/*   Updated: 2017/03/17 21:25:37 by apisotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*free_list(t_list *head)
{
	t_list	*next;

	while (head)
	{
		free(head->content);
		next = head->next;
		ft_memdel((void**)&head);
		head = next;
	}
	return (NULL);
}
