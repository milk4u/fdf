/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 19:18:03 by apisotsk          #+#    #+#             */
/*   Updated: 2017/03/15 17:15:55 by apisotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include "./libft.h"

typedef struct		s_file
{
	unsigned long	read_bytes;
	int				fd;
	char			*data;
	char			*tmp;
	struct s_file	*next;
}					t_file;

int					get_next_line(const int fd, char **line);

#endif
