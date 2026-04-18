/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 14:08:42 by pang              #+#    #+#             */
/*   Updated: 2026/04/18 17:29:49 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	exit_error(char *msg)
{
	ft_printf("Error: %s\n", msg);
	exit(EXIT_FAILURE);
}

void	free_map(t_map *map)
{
	int	count;

	if (!map)
		return ;
	if (map->grid)
	{
		count = 0;
		while (map->grid[count])
		{
			free(map->grid[count]);
			count++;
		}
		free(map->grid);
	}
	free(map);
}

void	freealloc_exit(t_map *map, char *msg)
{
	free_map(map);
	ft_printf("Error %s\n", msg);
	exit(EXIT_FAILURE);
}

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
