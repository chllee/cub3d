/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_storage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:12:39 by pang              #+#    #+#             */
/*   Updated: 2026/04/18 22:40:58 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

// strip newline
void	strip_newline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

// read map
static int	read_map(int fd, t_map *map)
{
	char	*line;
	int		index;
	int		len;

	index = 0;
	len = 0;
	map->col_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		strip_newline(line);
		if (!empty_line(line))
		{
			map->grid[index++] = line;
			len = ft_strlen(line);
			if (len > map->col_count)
				map->col_count = len;
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	map->grid[index] = NULL;
	return (index);
}

// Store map into 3D array
t_map	*store_map(char *filename, int lines_count)
{
	int		fd;
	t_map	*map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_error("Store map file cannot be opened");
	map = malloc(sizeof(t_map));
	if (!map)
		exit_error("Map allocation fail\n");
	map->grid = malloc(sizeof(char *) * (lines_count + 1));
	if (!map->grid)
		freealloc_exit(map, "Map grid allocation fail\n");
	map->row_count = read_map(fd, map);
	close(fd);
	return (map);
}
