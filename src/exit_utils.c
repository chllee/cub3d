/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 14:08:42 by pang              #+#    #+#             */
/*   Updated: 2026/04/19 19:55:28 by pang             ###   ########.fr       */
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

void	freealloc_exit(t_map *map, char *msg)
{
	free_map(map);
	ft_printf("Error %s\n", msg);
	exit(EXIT_FAILURE);
}
