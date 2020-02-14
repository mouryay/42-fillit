/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myadaval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 20:01:45 by myadaval          #+#    #+#             */
/*   Updated: 2020/02/13 01:34:14 by myadaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**make_map(int map_size)
{
	char	**map;
	int		i;
	int		j;

	map = malloc(sizeof(char*) * map_size);
	if (!map)
		return (0);
	i = 0;
	while (i < map_size)
	{
		map[i] = malloc(sizeof(char) * map_size + 1);
		if (!map[i])
			return (0);
		++i;
	}
	i = 0;
	while (i < map_size)
	{
		j = 0;
		while (j < map_size)
			map[i][j++] = '.';
		map[i][j] = '\0';
		++i;
	}
	return (map);
}

void		print_map(char **map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		write(1, map[i], size);
		write(1, "\n", 1);
		++i;
	}
}

void		free_map(char **map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		++i;
	}
	free(map);
}

void		fillit(t_tetri *list, int piececount)
{
	char	**map;
	int		map_size;

	map_size = 2;
	while (map_size * map_size < piececount * 4)
		++map_size;
	map = make_map(map_size);
	while (!solve_map(list, map, map_size))
	{
		free_map(map, map_size);
		map = make_map(++map_size);
	}
	print_map(map, map_size);
	free_map(map, map_size);
}
