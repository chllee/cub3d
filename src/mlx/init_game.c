/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 23:34:07 by pang              #+#    #+#             */
/*   Updated: 2026/05/02 14:14:30 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

void	init_game(t_game *game, t_map *map)
{
	ft_bzero(game, sizeof(t_game));
	game->player.pos_x = (double)map->p_start_x + 0.5;
	game->player.pos_y = (double)map->p_start_y + 0.5;
	if (map->p_start_dir == 'N')
	{
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
	}
	else if (map->p_start_dir == 'S')
	{
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
	}
	else if (map->p_start_dir == 'W')
	{
		game->player.dir_x = -1;
		game->player.plane_y = 0.66;
	}
	else if (map->p_start_dir == 'E')
	{
		game->player.dir_x = 1;
		game->player.plane_y = -0.66;
	}		
}
