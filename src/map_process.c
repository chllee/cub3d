/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 16:47:07 by pang              #+#    #+#             */
/*   Updated: 2026/04/18 23:27:21 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

bool	empty_line(const char *line)
{
	if (!line)
		return (true);
	while (*line)
	{
		if (!(*line == ' ' || (*line >= 7 && *line <= 13)))
			return (false);
		line++;
	}
	return (true);
}

static int	count_row(char *filename)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_error("Count lines file cannot open");
	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		strip_newline(line);
		if (!empty_line(line))
			count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

void	map_validity(t_map *map)
{
	valid_char(map);
	check_player(map);
}

t_map	*process_map(char *filename)
{
	int		fd;
	t_map	*map;
	int		lines_count;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_error("File check cannot open");
	lines_count = count_row(filename);
	close(fd);
	if (lines_count <= 0)
		exit_error("Empty map\n");
	map = store_map(filename, lines_count);

	ft_printf("process_map: lines count: %d\n", lines_count);
	ft_printf("process_map map->row_count: %d\n", map->row_count);
	ft_printf("process_map map->col_count: %d\n", map->col_count);
	print_map(map);
	map_validity(map);
	return (map);
}
