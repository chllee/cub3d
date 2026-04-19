/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 17:19:46 by pang              #+#    #+#             */
/*   Updated: 2026/04/19 20:44:59 by pang             ###   ########.fr       */
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

/* static void	map_validity(t_map *map)
{
	valid_char(map);
	check_player(map);
	boundaries_check(map);
} */

t_map	*process_file(char *filename)
{
	int		fd;
	t_map	*map;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_error("Cannot open file");
	map = malloc(sizeof(t_map));
	if (!map)
		exit_error("Map allocation fail\n");
	ft_bzero(map, sizeof(t_map));
	while ((line = get_next_line(fd)))
	{
		strip_newline(line);
		if (empty_line(line))
		{
			free(line);
			continue ;
		}
		if (is_mapline(line))
		{
			if (map->texture_count < 6)
			{
				free(line);
				freealloc_exit(map, "Missing headers before map");
			}
			free(line);
			store_map(fd, map);
			print_map(map);
			break ;
		}
		path_allocation(line, map);
		free(line);
	}
	close(fd);
	//map_validity(map);
	return (map);
}
	

void	path_allocation(char *str, t_map *map)
{
	char	*path;

	if (ft_isspace(str[2]))
	{
		path = str + 2;
		while (*path && ft_isspace(*path))
			path++;
	}
	if (ft_strncmp(str, "NO", 2) == 0)
		map->no_path = ft_strtrim(path, "\n ");
	if (ft_strncmp(str, "SO", 2) == 0)
		map->so_path = ft_strtrim(path, "\n ");
	if (ft_strncmp(str, "WE", 2) == 0)
		map->we_path = ft_strtrim(path, "\n ");
	if (ft_strncmp(str, "EA", 2) == 0)
		map->ea_path = ft_strtrim(path, "\n ");
}
