/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:15:46 by apisotsk          #+#    #+#             */
/*   Updated: 2017/03/03 19:16:55 by apisotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static t_file		*init_file(int fd_)
{
	t_file	*file;

	if (!(file = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	if (!(file->data = ft_strnew(0)))
		return (NULL);
	file->tmp = NULL;
	file->fd = fd_;
	file->read_bytes = 0;
	file->next = NULL;
	return (file);
}

static void			file_push_back(t_file **head, t_file *file)
{
	t_file				*tmp;

	if (head && *head)
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = file;
	}
	else if (file)
		head = &file;
}

static t_file		*get_file_by_fd(t_file **head, int fd_)
{
	t_file	*new;

	new = *head;
	while (new)
	{
		if (new->fd == fd_)
			return (new);
		new = new->next;
	}
	new = init_file(fd_);
	file_push_back(head, new);
	return (new);
}

static int			return_line(t_file **file, char **line)
{
	char			*n_pos;

	if (ft_strlen((*file)->data))
	{
		if (!(n_pos = ft_strchr((*file)->data, '\n')))
			n_pos = (*file)->data + ft_strlen((*file)->data);
		if (!(*line = ft_strsub((*file)->data, 0, n_pos - (*file)->data)))
			*line = ft_strnew(0);
		(*file)->tmp = (*file)->data;
		(*file)->data = ft_strsub((*file)->data, n_pos - (*file)->data + 1.,
			ft_strlen((*file)->data) - 1);
		ft_memdel((void**)&((*file)->tmp));
		return (1);
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	t_file			*cur;
	static t_file	*head;

	if (fd == -1 || BUFF_SIZE <= 0 || read(fd, buff, 0) == -1 || !line)
		return (-1);
	if (!head)
		if (!(head = get_file_by_fd(&head, fd)))
			return (-2);
	if (!(cur = get_file_by_fd(&head, fd)))
		return (-2);
	while (ft_strchr(cur->data, '\n') == NULL)
	{
		if ((cur->read_bytes = read(fd, buff, BUFF_SIZE)) == -1.)
			return (-2);
		if (cur->read_bytes == 0)
			return (return_line(&cur, line));
		buff[cur->read_bytes] = '\0';
		cur->tmp = cur->data;
		cur->data = ft_strjoin(cur->tmp, buff);
		ft_memdel((void**)&(cur->tmp));
	}
	return (return_line(&cur, line));
}
