/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 21:19:27 by apisotsk          #+#    #+#             */
/*   Updated: 2017/03/17 21:21:26 by apisotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/get_next_line.h"
#include "../includes/point.h"
#include "../includes/errors.h"

static t_point	**cut_lines_to_points(t_list **head, size_t size_of_list)
{
	char		**arr;
	t_point		**map;
	t_list		*curr;
	int			i;
	int			j;

	if (!(map = (t_point**)malloc(sizeof(t_point*) * size_of_list)))
		p_error( __FILE__, __FUNCTION__, __LINE__, MALLOC_ERR);
	curr = *head;
	i = -1;
	while (curr)
	{
		if ((!(arr = ft_strsplit((char*)curr->content, ' '))) ||
			(!(map[++i] = (t_point*)malloc(sizeof(t_point) * arr_size(arr)))))
			p_error( __FILE__, __FUNCTION__, __LINE__, MALLOC_ERR);
		j = -1;
		while (arr[++j])
		{
			init_point(&map[i][j], i, j, ft_atoi(arr[j]));
			ft_memdel((void**)&arr[j]);
		}
		curr = curr->next;
	}
	return (map);
}

t_point			**read_map_from_file(int fd)
{
	t_point		**map;
	t_list		*head;
	t_list		*curr;
	char		*line;
	short		err_code;

	head = NULL;
	while ((err_code = get_next_line(fd, &line)) == 1)
	{
		if (!(curr = ft_lstnew(line, ft_strlen(line))))
			p_error( __FILE__, __FUNCTION__, __LINE__, MALLOC_ERR);
		ft_list_push_back(&head, curr);
	}
	if (err_code < 0)
		p_error( __FILE__, __FUNCTION__, __LINE__, FILE_ERR);
	map = cut_lines_to_points(&head, ft_lstcount(head));
	free_list(head);
	close(fd);
	return (map);
}
