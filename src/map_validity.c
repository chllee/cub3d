/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 21:48:34 by pang              #+#    #+#             */
/*   Updated: 2026/04/18 23:26:50 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

// check that it contains 01, NSEW
void	valid_char(t_map *map)
{
	char	c;

	map->row = 0;
	while (map->grid[map->row])
	{
		map->col = 0;
		while (map->grid[map->row][map->col])
		{
			c = map->grid[map->row][map->col];
			if (c != '0' && c != '1' && c != ' ' && c != 'N'
				&& c != 'S' && c != 'E' && c != 'W')
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
	while (map->row < map->row_count)
	{
		map->col = 0;
		while (map->col < (int)ft_strlen(map->grid[map->row]))
		{
			if (map->grid[map->row][map->col] == 'N'
				|| map->grid[map->row][map->col] == 'S'
				|| map->grid[map->row][map->col] == 'E'
				|| map->grid[map->row][map->col] == 'W')
				p++;
			map->col++;
		}
		map->row++;
	}
	if (p != 1)
		freealloc_exit(map, "Single player only");
	ft_printf("check_player: %d\n", p);
}


// flood fill boundaries check



// flood fill player can get to the end