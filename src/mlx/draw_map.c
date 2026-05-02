/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 00:35:20 by pang              #+#    #+#             */
/*   Updated: 2026/05/02 14:16:19 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

static void	draw_rect(t_game *game, int start_x, int start_y, int colour)
{
	int	x;
	int	y;

	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			mlx_pixel_put(game->mlx_ptr, game->win_ptr,
				start_x + x, start_y + y, colour);

			x++;
		}
		y++;
	}
}

static void	draw_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '1')
		draw_rect(game, x *TILE_SIZE, y * TILE_SIZE, 0x6400);
	else if (tile == ' ')
		draw_rect(game, x *TILE_SIZE, y * TILE_SIZE, 0x0);
	else
		draw_rect(game, x *TILE_SIZE, y * TILE_SIZE, 0xb03060);
}

static void	player_dir(t_game *game, int center_x, int center_y)
{
	int	i;
	int	fx;
	int	fy;

	i = 0;
	while (i < 16)
	{
		fx = center_x + (game->player.dir_x * i);
		fy = center_y + (game->player.dir_y * i);
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, fx, fy, 0xFF000000);
		i++;
	}
}

// a^2 + b^s <= r^2
void	draw_player(t_game *game)
{
	int	dx;
	int	dy;
	int	center_x;
	int	center_y;

	center_x = (int)(game->player.pos_x * TILE_SIZE);
	center_y = (int)(game->player.pos_y * TILE_SIZE);

	dy = -RADIUS;
	while (dy <= RADIUS)
	{
		dx = -RADIUS;
		while (dx <= RADIUS)
		{
			if (dx * dx + dy * dy <= RADIUS * RADIUS)
				mlx_pixel_put(game->mlx_ptr, game->win_ptr,
					center_x + dx, center_y + dy, 0xFFFFFF);
			dx++;
		}
		dy++;
	}
	player_dir(game, center_x, center_y);
}

void	draw_map(t_game *game, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->y_max)
	{
		x = 0;
		while ((size_t)x < ft_strlen(map->grid[y]))
		{
			draw_tile(game, map->grid[y][x], x, y);
			x++;
		}
		y++;
	}
}
