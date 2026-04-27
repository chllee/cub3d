/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_storage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:12:39 by pang              #+#    #+#             */
/*   Updated: 2026/04/27 07:13:57 by pang             ###   ########.fr       */
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

static int	read_map(int fd, t_map *map)
{
	char	*line;
	int		index;
	int		found_empty_after_map;

	index = 0;
	found_empty_after_map = 0;
	line = get_next_line(fd);
	while (line)
	{
		strip_newline(line);
		if (index > 0 && empty_line(line))
			found_empty_after_map = 1;
		else if (!empty_line(line))
		{
			if (found_empty_after_map)
			{
				free(line);
				clear_gnl_buffer(fd);
				freealloc_exit(map, "Content found after map end");
			}
			map->grid[index++] = ft_strdup(line);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (index);
}

t_map	*store_map(char *filename, t_map *map, int lines_tomap)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		freealloc_exit(map, "Store file cannot open");
	i = 0;
	while (i < lines_tomap)
	{
		line = get_next_line(fd);
		if (line)
			free(line);
		i++;
	}
	map->grid = malloc(sizeof(char *) * 1024);
	if (!map->grid)
		freealloc_exit(map, "Map grid allocation fail");
	ft_bzero(map->grid, 1024);
	map->y_max = read_map(fd, map);
	close(fd);
	return (map);
}
