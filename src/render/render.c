/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:00:00 by chllee            #+#    #+#             */
/*   Updated: 2026/05/12 20:08:57 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall(t_map *map, int x, int y)
{
	char	c;

	if (y < 0 || y >= map->y_max || x < 0)
		return (1);
	if (!map->grid[y] || x >= (int)ft_strlen(map->grid[y]))
		return (1);
	c = map->grid[y][x];
	return (c != '0' && c != 'N' && c != 'S' && c != 'E' && c != 'W');
}

static void	get_wall_bounds(double perp_dist, int *top, int *bot)
{
	int	line_h;

	if (perp_dist < 0.1)
		perp_dist = 0.1;
	line_h = (int)(WIN_H / perp_dist);
	*top = WIN_H / 2 - line_h / 2;
	*bot = WIN_H / 2 + line_h / 2;
	if (*top < 0)
		*top = 0;
	if (*bot >= WIN_H)
		*bot = WIN_H - 1;
}

void	render_frame(t_game *g)
{
	t_ray	ray;
	t_wall	wall;
	int		x;

	x = 0;
	while (x < WIN_W)
	{
		cast_ray(&ray, &g->player, g->map, x);
		wall.x = x;
		get_wall_bounds(ray.perp_wall_dist, &wall.top, &wall.bot);
		draw_bg(g, &wall);
		draw_wall(g, &ray, &wall);
		x++;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->screen.img, 0, 0);
}
