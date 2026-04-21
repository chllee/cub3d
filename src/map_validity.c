/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 21:48:34 by pang              #+#    #+#             */
/*   Updated: 2026/04/21 21:30:02 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

// check that it contains 01, NSEW
void	valid_char(t_map *map)
{
	char	c;

	if (!map || !map->grid)
		freealloc_exit(map, "Empty map");
	map->row = 0;
	while (map->grid[map->row])
	{
		map->col = 0;
		while (map->grid[map->row][map->col])
		{
			c = map->grid[map->row][map->col];
			if (c != '0' && c != '1' && c != ' '
				&& c != 'N' && c != 'S' && c != 'E' && c != 'W')
				freealloc_exit(map, "Invalid characters");
			map->col++;
		}
		map->row++;
	}
}

// single player
void	check_player(t_map *map)
{
	int	p;

	p = 0;
	map->row = 0;
	while (map->row < map->y_max)
	{
		map->col = 0;
		while (map->col < (int)ft_strlen(map->grid[map->row]))
		{
			if (ft_strchr("NSEW", map->grid[map->row][map->col]))
			{
				map->p_start_x = map->col;
				map->p_start_y = map->row;
				map->p_start_dir = map->grid[map->row][map->col];
				p++;
			}
			map->col++;
		}
		map->row++;
	}
	if (p != 1)
		freealloc_exit(map, "Single player only");
}

// flood fill a copy of map
t_map	*copy_map(t_map *map)
{
	t_map	*copy;
	int		y;

	copy = malloc(sizeof(t_map));
	if (!copy)
		freealloc_exit(map, "Copy map allocation failed");
	ft_bzero(copy, sizeof(t_map));
	copy->grid = malloc(sizeof(char *) * (map->y_max + 1));
	if (!copy->grid)
		freealloc_exit(map, "Copy map grid alloc failed");
	copy->y_max = map->y_max;
	copy->x_max = map->x_max;
	y = 0;
	while (y < map->y_max)
	{
		copy->grid[y] = ft_strdup(map->grid[y]);
		if (!copy->grid[y])
			freealloc_exit(map, "Copy row alloc failed");
		y++;
	}
	copy->grid[y] = NULL;
	return (copy);
}

void	flood_fill(t_map *original, t_map *copy, int x, int y)
{
	int	line_len;

	if (y < 0 || y >= copy->y_max)
	{
		free_map(copy);
		freealloc_exit(original, "Map open to spaces");
	}
	line_len = (int)ft_strlen(copy->grid[y]);
	if (x < 0 || x >= line_len)
	{
		free_map(copy);
		freealloc_exit(original, "Map open to spaces");
	}
	if (copy->grid [y][x] == ' ' || copy->grid[y][x] == '\0')
	{
		free_map(copy);
		freealloc_exit(original, "Map open to spaces");
	}
	if (copy->grid[y][x] == '1' || copy->grid[y][x] == 'V')
		return ;
	copy->grid[y][x] = 'V';
	flood_fill(original, copy, x + 1, y);
	flood_fill(original, copy, x - 1, y);
	flood_fill(original, copy, x, y + 1);
	flood_fill(original, copy, x, y - 1);
}

// flood fill boundaries check
void	boundaries_check(t_map *map)
{
	t_map	*copy;

	copy = copy_map(map);
	flood_fill(map, copy, map->p_start_x, map->p_start_y);
	free_map(copy);
}

// flood fill player can get to the end