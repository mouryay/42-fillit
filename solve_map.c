/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myadaval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 00:35:39 by myadaval          #+#    #+#             */
/*   Updated: 2020/02/12 23:59:59 by myadaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		within_map(t_tetri *piece, int size, char axis)
{
	if (axis == 'y')
	{
		return (piece->coords[1] + piece->y_offset < size &&
				piece->coords[3] + piece->y_offset < size &&
				piece->coords[5] + piece->y_offset < size &&
				piece->coords[7] + piece->y_offset < size);
	}
	else
		return (piece->coords[0] + piece->x_offset < size &&
				piece->coords[2] + piece->x_offset < size &&
				piece->coords[4] + piece->x_offset < size &&
				piece->coords[6] + piece->x_offset < size);
}

int		overlap(t_tetri *piece, char **map)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (map[piece->coords[i + 1] + piece->y_offset]\
				[piece->coords[i] + piece->x_offset] != '.')
			return (1);
		i += 2;
	}
	return (0);
}

void	place(t_tetri *piece, char **map, char letter)
{
	int i;

	i = 0;
	while (i < 8)
	{
		map[piece->coords[i + 1] + piece->y_offset][piece->coords[i]\
			+ piece->x_offset] = letter;
		i += 2;
	}
}

int		solve_map(t_tetri *piece, char **map, int map_size)
{
	if (!piece)
		return (1);
	piece->y_offset = 0;
	piece->x_offset = 0;
	while (within_map(piece, map_size, 'y'))
	{
		while (within_map(piece, map_size, 'x'))
		{
			if (!overlap(piece, map))
			{
				place(piece, map, piece->pieceletter);
				if (solve_map(piece->next, map, map_size))
					return (1);
				else
					place(piece, map, '.');
			}
			++piece->x_offset;
		}
		piece->x_offset = 0;
		++piece->y_offset;
	}
	return (0);
}
