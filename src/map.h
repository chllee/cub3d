/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 14:08:25 by pang              #+#    #+#             */
/*   Updated: 2026/04/21 21:27:48 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_map
{
	char			**grid;
	int				x_max; //max col_count (width)
	int				y_max; //max row_count (height)
	int				row;
	int				col;
	int				p_start_x; // horizontal pos
	int				p_start_y; // veritcal pos
	char			p_start_dir;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	char			*f_path;
	char			*c_path;
	int				texture_count;
	int				f_rgb[3];
	int				c_rgb[3];
	unsigned int	f_hex;
	unsigned int	c_hex;
}	t_map;

// exit_utils.c
void	exit_error(char *msg);
void	free_map(t_map *map);
void	freealloc_exit(t_map *map, char *msg);
void	free_resources(t_map *map);

// map_storage.c
t_map	*store_map(char *filename, t_map *map, int lines_tomap);
void	strip_newline(char *line);

// map_validity.c
void	valid_char(t_map *map);
void	check_player(t_map *map);
t_map	*copy_map(t_map *map);
void	flood_fill(t_map *original, t_map *copy, int x, int y);
void	boundaries_check(t_map *map);

// utils.c
char	*skip_whitespace(char *str);
bool	empty_line(const char *line);
bool	is_mapline(char *line);
void	clear_gnl_buffer(int fd);
void	free_split(char **str);

// file_path.c
void	path_allocation(char *str, t_map *map);

// file_process.c
t_map	*process_file(char *filename);
void	file_ext(char *filename);
void	map_validity(t_map *map);

// texture_validity.c
void	valid_path(char *path, t_map *map);
void	valid_colours(char *str, t_map *map);

// file_rgb.c
void	hex_colours(t_map *map);
void	rgb_conversion(char *str, int *rgb_arr);

// z_print_map.h
t_map	*print_map(t_map *map);

#endif