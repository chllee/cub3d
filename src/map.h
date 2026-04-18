/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 14:08:25 by pang              #+#    #+#             */
/*   Updated: 2026/04/18 23:20:02 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>

typedef	struct s_map
{
	char	**grid;
	int		row_count; //max
	int		col_count; //max
	int		row;
	int		col;
}	t_map;


// map_utils.c
void	exit_error(char *msg);
void	file_ext(char *filename);
void	free_map(t_map *map);
void	freealloc_exit(t_map *map, char *msg);

// map_process.c
t_map	*process_map(char *filename);
bool	empty_line(const char *line);

// map_storage.c
t_map	*store_map(char *filename, int lines_count);
void	strip_newline(char *line);

// map_validity.c
void	valid_char(t_map *map);
void	check_player(t_map *map);


// z_print_map.h
t_map	*print_map(t_map *map);

#endif