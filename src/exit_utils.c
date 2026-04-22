/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 14:08:42 by pang              #+#    #+#             */
/*   Updated: 2026/04/21 21:22:28 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	exit_error(char *msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
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

void	free_resources(t_map *map)
{
	if (!map)
		return ;
	if (map->no_path)
		free(map->no_path);
	if (map->so_path)
		free(map->so_path);
	if (map->we_path)
		free(map->we_path);
	if (map->ea_path)
		free(map->ea_path);
	if (map->f_path)
		free(map->f_path);
	if (map->c_path)
		free(map->c_path);
	free_map(map);
}

void	freealloc_exit(t_map *map, char *msg)
{
	free_resources(map);
	ft_printf("Error: %s\n", msg);
	exit(EXIT_FAILURE);
}
