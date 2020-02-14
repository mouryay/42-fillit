/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myadaval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 16:36:09 by myadaval          #+#    #+#             */
/*   Updated: 2020/02/13 00:46:40 by myadaval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef	struct		s_tetri
{
	int				coords[8];
	char			pieceletter;
	int				x_offset;
	int				y_offset;
	struct s_tetri	*next;
}					t_tetri;

int					valid(char *buf, int size);
int					char_count(char *buf);
int					adj_count(char *buf);
t_tetri				*makelist(char *buf, int size, int *countptr);
t_tetri				*makepiece(char *buf, char letter);
t_tetri				*align(t_tetri *piece);
void				free_list(t_tetri *list);
void				fillit(t_tetri *list, int piececount);
char				**make_map(int mapsize);
void				print_map(char **map, int size);
void				free_map(char **map, int size);
int					solve_map(t_tetri *piece, char **map, int map_size);
int					within_map(t_tetri *piece, int size, char axis);
int					overlap(t_tetri *piece, char **map);
void				place(t_tetri *piece, char **map, char letter);

#endif
