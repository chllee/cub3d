/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_storage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:12:39 by pang              #+#    #+#             */
/*   Updated: 2026/04/18 18:08:32 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

// strip white space
static void	strip_space(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && (((line[len - 1] >= 7) && line[len - 1] <= 13)
			|| line[len - 1] == ' '))
		line[len - 1] = '\0';
}

// read map
static int	read_map(int fd, t_map *map)
{
	char	*line;
	int		index;
	int		len;

	index = 0;
	line = get_next_line(fd);
	while (line)
	{
		strip_space(line);
		if (line[0] != '\0')
		{
			len = ft_strlen(line);
			if (len > map->col_count)
				map->col_count = len;
			grid[index++] = line;
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	grid[index] = NULL;
	return (index);
}

// Store map into 3D array
t_map	*store_map(char *filename, int lines_count)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (!fd)
		exit_error("Store map file cannot be opened");
	map = malloc(sizeof(t_map));
	if (!map)
		exit_error("Map allocation fail\n");
	map->grid = malloc(sizeof(char *) * (lines_count + 1));
	if (!map->grid)
		freealloc_exit(map, "Map grid allocation fail\n");
	map->row_count = read_map(fd, map->grid);
	close(fd);
	return (map);
}
