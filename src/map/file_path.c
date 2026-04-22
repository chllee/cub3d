/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 21:22:35 by pang              #+#    #+#             */
/*   Updated: 2026/04/21 21:22:37 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	set_path(char *str, char *path, t_map *map)
{
	if (ft_strncmp(str, "NO", 2) == 0 && !map->no_path)
		map->no_path = ft_strtrim(path, "\n ");
	else if (ft_strncmp(str, "SO", 2) == 0 && !map->so_path)
		map->so_path = ft_strtrim(path, "\n ");
	else if (ft_strncmp(str, "WE", 2) == 0 && !map->we_path)
		map->we_path = ft_strtrim(path, "\n ");
	else if (ft_strncmp(str, "EA", 2) == 0 && !map->ea_path)
		map->ea_path = ft_strtrim(path, "\n ");
	else if (ft_strncmp(str, "F", 1) == 0 && !map->f_path)
		map->f_path = ft_strtrim(path, "\n ");
	else if (ft_strncmp(str, "C", 1) == 0 && !map->c_path)
		map->c_path = ft_strtrim(path, "\n ");
	else
		return ;
}

void	path_allocation(char *str, t_map *map)
{
	char	*path;

	path = NULL;
	while (*str && ft_isspace(*str))
		str++;
	if (!*str)
		return ;
	if (ft_strncmp(str, "NO", 2) == 0 || ft_strncmp(str, "SO", 2) == 0
		|| ft_strncmp(str, "WE", 2) == 0 || ft_strncmp(str, "EA", 2) == 0)
		path = str + 2;
	else if (ft_strncmp(str, "F", 1) == 0 || ft_strncmp(str, "C", 1) == 0)
		path = str + 1;
	else
		return ;
	while (*path && ft_isspace(*path))
		path++;
	set_path(str, path, map);
	map->texture_count++;
}
