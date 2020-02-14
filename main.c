/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myadaval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:32:04 by myadaval          #+#    #+#             */
/*   Updated: 2020/02/13 02:05:39 by myadaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	buf[548];
	int		fd;
	int		bytecount;
	int		piececount;
	t_tetri	*list;

	if (argc != 2)
	{
		write(1, "usage: ./fillit <filename>\n", 27);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	bytecount = read(fd, buf, 548);
	close(fd);
	buf[bytecount] = '\0';
	if ((bytecount > 545 || bytecount < 20) || !valid(buf, bytecount))
	{
		write(1, "error\n", 6);
		return (1);
	}
	piececount = 0;
	list = makelist(buf, bytecount, &piececount);
	fillit(list, piececount);
	free_list(list);
	return (0);
}
