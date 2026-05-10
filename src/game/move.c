/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:00:00 by chllee            #+#    #+#             */
/*   Updated: 2026/05/10 00:00:00 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rotate(t_game *g, double speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = g->player.dir_x;
	old_plane_x = g->player.plane_x;
	g->player.dir_x = g->player.dir_x * cos(speed)
		- g->player.dir_y * sin(speed);
	g->player.dir_y = old_dir_x * sin(speed)
		+ g->player.dir_y * cos(speed);
	g->player.plane_x = g->player.plane_x * cos(speed)
		- g->player.plane_y * sin(speed);
	g->player.plane_y = old_plane_x * sin(speed)
		+ g->player.plane_y * cos(speed);
}

static void	move_player(t_game *g, double dx, double dy)
{
	double	nx;
	double	ny;

	nx = g->player.pos_x + dx;
	ny = g->player.pos_y + dy;
	if (!is_wall(g->map, (int)nx, (int)g->player.pos_y))
		g->player.pos_x = nx;
	if (!is_wall(g->map, (int)g->player.pos_x, (int)ny))
		g->player.pos_y = ny;
}

static void	handle_rotation(t_game *g)
{
	if (g->keys.left)
		rotate(g, -ROT_SPEED);
	if (g->keys.right)
		rotate(g, ROT_SPEED);
}

void	handle_movement(t_game *g)
{
	handle_rotation(g);
	if (g->keys.w)
		move_player(g, g->player.dir_x * MOVE_SPEED,
			g->player.dir_y * MOVE_SPEED);
	if (g->keys.s)
		move_player(g, -g->player.dir_x * MOVE_SPEED,
			-g->player.dir_y * MOVE_SPEED);
	if (g->keys.a)
		move_player(g, g->player.dir_y * MOVE_SPEED,
			-g->player.dir_x * MOVE_SPEED);
	if (g->keys.d)
		move_player(g, -g->player.dir_y * MOVE_SPEED,
			g->player.dir_x * MOVE_SPEED);
}
