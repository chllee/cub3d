/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_storage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:12:39 by pang              #+#    #+#             */
/*   Updated: 2026/04/19 20:40:33 by pang             ###   ########.fr       */
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

/* static int	count_row(int fd)
{
	int		count;
	char	*line;

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
} */

// read map
static int	read_map(int fd, t_map *map)
{
	char	*line;
	int		index;

	index = 0;
	while ((line = get_next_line(fd)))
	{
		strip_newline(line);
		if (index > 0 && empty_line(line))
		{
			free(line);
			break ;
		}
		map->grid[index] = ft_strdup(line);
		if ((int)ft_strlen(line) > map->x_max)
			map->x_max = ft_strlen(line);
		index++;
		free(line);
	}
	map->grid[index] = NULL;
	return (index);
}

// Store map into 3D array
/* t_map	*store_map(char *filename, t_map *map)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		freealloc_exit(map, "Unable to store map");
	map->y_max = count_row(fd);
	close(fd);
	map->grid = malloc(sizeof(char *) * (map->y_max + 1));
	if (!map->grid)
		freealloc_exit(map, "Map grid allocation fail\n");
	fd = open(filename, O_RDONLY);
	read_map(fd, map);
	close(fd);
	return (map);
} */

t_map	*store_map(int fd, t_map *map)
{
	int	rows;

	// Rough upper bound or use a dynamic array; simplest: just read and count
	map->grid = malloc(sizeof(char *) * 1024); // temp ceiling
	if (!map->grid)
		freealloc_exit(map, "Map grid allocation fail");
	rows = read_map(fd, map);
	map->y_max = rows;
	// optionally realloc to exact size here
	return (map);
}