/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myadaval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 20:01:02 by myadaval          #+#    #+#             */
/*   Updated: 2020/02/13 02:09:51 by myadaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		char_count(char *buf)
{
	int	block_count;
	int i;

	block_count = 0;
	i = 0;
	while (i < 19)
	{
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			return (0);
		if (buf[i] == '\n' && !((i + 1) % 5 == 0))
			return (0);
		if (buf[i] == '#')
			++block_count;
		++i;
	}
	if (buf[i] && buf[i] != '\n')
		return (0);
	return (block_count);
}

int		adj_count(char *buf)
{
	int i;
	int adj_count;

	i = 0;
	adj_count = 0;
	while (i < 19)
	{
		if (buf[i] == '#')
		{
			if (i - 1 >= 0 && buf[i - 1] == '#')
				++adj_count;
			if (i + 1 < 19 && buf[i + 1] == '#')
				++adj_count;
			if (i > 4 && buf[i - 5] == '#')
				++adj_count;
			if (i < 15 && buf[i + 5] == '#')
				++adj_count;
		}
		++i;
	}
	return (adj_count);
}

int		valid(char *buf, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (char_count(buf + i) != 4)
			return (0);
		if (adj_count(buf + i) != 6 && adj_count(buf + i) != 8)
			return (0);
		i += 21;
	}
	if (buf[i - 1] == '\0')
		return (1);
	else
		return (0);
}
