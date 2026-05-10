/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:00:00 by chllee            #+#    #+#             */
/*   Updated: 2026/05/10 00:00:00 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_plane(t_player *p, char dir)
{
	if (dir == 'N')
		p->plane_x = 0.66;
	else if (dir == 'S')
		p->plane_x = -0.66;
	else
		p->plane_x = 0;
	if (dir == 'E')
		p->plane_y = 0.66;
	else if (dir == 'W')
		p->plane_y = -0.66;
	else
		p->plane_y = 0;
}

static void	set_player_dir(t_player *p, char dir)
{
	if (dir == 'E')
		p->dir_x = 1;
	else if (dir == 'W')
		p->dir_x = -1;
	else
		p->dir_x = 0;
	if (dir == 'S')
		p->dir_y = 1;
	else if (dir == 'N')
		p->dir_y = -1;
	else
		p->dir_y = 0;
	set_plane(p, dir);
}

static int	init_screen(t_game *g)
{
	g->screen.img = mlx_new_image(g->mlx, WIN_W, WIN_H);
	if (!g->screen.img)
		return (0);
	g->screen.addr = mlx_get_data_addr(g->screen.img,
			&g->screen.bpp, &g->screen.line_len, &g->screen.endian);
	return (1);
}

int	init_game(t_game *g, t_map *map)
{
	g->map = map;
	g->mlx = mlx_init();
	if (!g->mlx)
		return (0);
	g->win = mlx_new_window(g->mlx, WIN_W, WIN_H, "cub3D");
	if (!g->win)
		return (0);
	if (!load_textures(g))
		return (0);
	g->player.pos_x = g->map->p_start_x + 0.5;
	g->player.pos_y = g->map->p_start_y + 0.5;
	set_player_dir(&g->player, g->map->p_start_dir);
	ft_memset(&g->keys, 0, sizeof(t_keys));
	return (init_screen(g));
}
