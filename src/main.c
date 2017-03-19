/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apisotsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 21:27:09 by apisotsk          #+#    #+#             */
/*   Updated: 2017/03/17 21:28:05 by apisotsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "point.h"

void	print_map(t_point **map)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			printf ("%d:%d:%d ", map[i][j].x, map[i][j].y, map[i][j].z);
		printf ("\n");
	}
}

int		main(int argc, char **argv) {

	t_point	**map;
	map = read_map_from_file(open(argv[1], O_RDONLY));
	print_map(map);
    return 0;
}
