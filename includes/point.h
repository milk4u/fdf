/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 21:26:37 by apisotsk          #+#    #+#             */
/*   Updated: 2017/03/17 21:26:38 by apisotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

void			init_point(t_point *point, int x, int y, int z);
t_point			**read_map_from_file(int fd);

#endif
