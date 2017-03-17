/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:30:29 by apisotsk          #+#    #+#             */
/*   Updated: 2016/11/28 17:31:18 by apisotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*new_list;

	if (!lst)
		return (NULL);
	new_list = f(lst);
	start = new_list;
	while (lst->next)
	{
		lst = lst->next;
		new_list->next = f(lst);
		new_list = new_list->next;
	}
	return (start);
}
