/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:00:00 by chllee            #+#    #+#             */
/*   Updated: 2026/05/12 20:53:20 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_ray(t_ray *r, t_player *p, int x)
{
	r->camera_x = 2 * x / (double)WIN_W - 1;
	r->ray_dir_x = p->dir_x + p->plane_x * r->camera_x;
	r->ray_dir_y = p->dir_y + p->plane_y * r->camera_x;
	r->map_x = (int)p->pos_x;
	r->map_y = (int)p->pos_y;
	r->hit = 0;
	if (r->ray_dir_x == 0)
		r->delta_dist_x = 1e30;
	else
		r->delta_dist_x = fabs(1.0 / r->ray_dir_x);
	if (r->ray_dir_y == 0)
		r->delta_dist_y = 1e30;
	else
		r->delta_dist_y = fabs(1.0 / r->ray_dir_y);
}

static void	calc_step(t_ray *r, t_player *p)
{
	if (r->ray_dir_x < 0)
		r->step_x = -1;
	else
		r->step_x = 1;
	if (r->ray_dir_y < 0)
		r->step_y = -1;
	else
		r->step_y = 1;
	if (r->ray_dir_x < 0)
		r->side_dist_x = (p->pos_x - r->map_x) * r->delta_dist_x;
	else
		r->side_dist_x = (r->map_x + 1.0 - p->pos_x) * r->delta_dist_x;
	if (r->ray_dir_y < 0)
		r->side_dist_y = (p->pos_y - r->map_y) * r->delta_dist_y;
	else
		r->side_dist_y = (r->map_y + 1.0 - p->pos_y) * r->delta_dist_y;
}

static void	dda(t_ray *r, t_map *map)
{
	while (!r->hit)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (is_wall(map, r->map_x, r->map_y))
			r->hit = 1;
	}
}

void	cast_ray(t_ray *r, t_player *p, t_map *map, int x)
{
	init_ray(r, p, x);
	calc_step(r, p);
	dda(r, map);
	if (r->side == 0)
		r->perp_wall_dist = (r->map_x - p->pos_x
				+ (1 - r->step_x) / 2.0) / r->ray_dir_x;
	else
		r->perp_wall_dist = (r->map_y - p->pos_y
				+ (1 - r->step_y) / 2.0) / r->ray_dir_y;
}
