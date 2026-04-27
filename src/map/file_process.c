/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 17:19:46 by pang              #+#    #+#             */
/*   Updated: 2026/04/27 22:00:10 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

// Check for file extension
void	file_ext(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		exit_error("Filename invalid");
	if (ft_strcmp((filename + len - 4), ".cub") != 0)
		exit_error("Invalid filename extension");
}

static t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		exit_error("Map allocation fail\n");
	ft_bzero(map, sizeof(t_map));
	return (map);
}

static int	handle_line(char *line, t_map *map, int fd)
{
	char	*temp;

	strip_newline(line);
	temp = line;
	while (*temp && ft_isspace(*temp))
		temp++;
	if (*temp == '\0')
		return (0);
	if (is_mapline(temp))
	{
		if (map->texture_count != 6)
		{
			free(line);
			clear_gnl_buffer(fd);
			freealloc_exit(map, "Headers issue");
		}
		return (1);
	}
	path_allocation(line, map);
	return (0);
}

static t_map	*found_map(char *filename, t_map *map, int fd, int line_count)
{
	clear_gnl_buffer(fd);
	close(fd);
	store_map(filename, map, line_count - 1);
	map_validity(map);
	return (map);
}

t_map	*process_file(char *filename)
{
	int		fd;
	t_map	*map;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_error("Cannot open file");
	map = init_map();
	line = get_next_line(fd);
	while (line)
	{
		line_count++;
		if (handle_line(line, map, fd))
		{
			free(line);
			return (found_map(filename, map, fd, line_count));
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	freealloc_exit(map, "No map found");
	return (NULL);
}
