/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makelist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myadaval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 22:47:48 by myadaval          #+#    #+#             */
/*   Updated: 2020/02/13 01:38:53 by myadaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_list(t_tetri *list)
{
	t_tetri *tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

t_tetri	*align(t_tetri *piece)
{
	while (piece->coords[0] > 0 && piece->coords[2] > 0 &&\
			piece->coords[4] > 0 && piece->coords[6] > 0)
	{
		piece->coords[0] -= 1;
		piece->coords[2] -= 1;
		piece->coords[4] -= 1;
		piece->coords[6] -= 1;
	}
	while (piece->coords[1] > 0 && piece->coords[3] > 0 &&\
			piece->coords[5] > 0 && piece->coords[7] > 0)
	{
		piece->coords[1] -= 1;
		piece->coords[3] -= 1;
		piece->coords[5] -= 1;
		piece->coords[7] -= 1;
	}
	return (piece);
}

t_tetri	*makepiece(char *buf, char letter)
{
	t_tetri	*piece;
	int		i;
	int		j;

	i = 0;
	j = 0;
	piece = malloc(sizeof(t_tetri));
	if (!piece)
		return (NULL);
	while (i < 19)
	{
		if (buf[i] == '#')
		{
			piece->coords[j] = i % 5;
			piece->coords[j + 1] = i / 5;
			j += 2;
			piece->pieceletter = letter;
			piece->next = NULL;
			piece->x_offset = 0;
			piece->y_offset = 0;
		}
		++i;
	}
	return (align(piece));
}

t_tetri	*makelist(char *buf, int size, int *countptr)
{
	int		i;
	t_tetri	*list;
	t_tetri	*tmp;
	char	letter;

	i = 0;
	letter = 'A';
	while (i < size)
	{
		if (letter == 'A')
		{
			list = makepiece(buf + i, letter);
			tmp = list;
		}
		else
		{
			tmp->next = makepiece(buf + i, letter);
			tmp = tmp->next;
		}
		++*countptr;
		++letter;
		i += 21;
	}
	return (list);
}
