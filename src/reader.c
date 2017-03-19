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

#include <stdio.h>
#include "../includes/point.h"

static void		print_error(int exit_code)
{
	if (exit_code == -1)
		perror("/tError. Missing file or bad access rigths.");
	if (exit_code == -2)
		perror("/tError. Can't allocate memory.");
	exit(exit_code);
}

static size_t	arr_size(char **arr)
{
	size_t		size;

	size = 0;
	if (arr && *arr)
		while (arr[size])
			size++;
	return (size);
}

static void		init_point(t_point *point, int x, int y, int z)
{
	point->x = x;
	point->y = y;
	point->z = z;
}

static t_point	**cut_lines_to_points(t_list **head, size_t size_of_list)
{
	char		**arr;
	t_point		**map;
	t_list		*curr;
	int			i;
	int			j;

	if (!(map = (t_point**)malloc(sizeof(t_point*) * size_of_list)))
		print_error(-2);
	curr = *head;
	i = -1;
	while (curr)
	{
		if ((!(arr = ft_strsplit((char*)curr->content, ' '))) ||
			(!(map[++i] = (t_point*)malloc(sizeof(t_point) * arr_size(arr)))))
			print_error(-2);
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
			print_error(-2);
		ft_list_push_back(&head, curr);
	}
	if (err_code < 0)
		print_error(err_code);
	map = cut_lines_to_points(&head, ft_lstcount(head));
	free_list(head);
	close(fd);
	return (map);
}
