/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:00:00 by chllee            #+#    #+#             */
/*   Updated: 2026/05/12 21:41:10 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	load_tex(t_game *g, char *path, int idx)
{
	g->tex[idx].img = mlx_xpm_file_to_image(g->mlx, path,
			&g->tex[idx].width, &g->tex[idx].height);
	if (!g->tex[idx].img)
		return (0);
	g->tex[idx].addr = mlx_get_data_addr(g->tex[idx].img,
			&g->tex[idx].bpp, &g->tex[idx].line_len, &g->tex[idx].endian);
	return (1);
}

int	get_tex_idx(t_ray *r)
{
	if (r->side == 0 && r->step_x > 0)
		return (TEX_EA);
	if (r->side == 0 && r->step_x < 0)
		return (TEX_WE);
	if (r->side == 1 && r->step_y > 0)
		return (TEX_SO);
	return (TEX_NO);
}

int	get_tex_x(t_ray *r, t_player *p, int tex_w)
{
	double	wall_x;
	int		tex_x;

	if (r->side == 0)
		wall_x = p->pos_y + r->perp_wall_dist * r->ray_dir_y;
	else
		wall_x = p->pos_x + r->perp_wall_dist * r->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * tex_w);
	if (r->side == 0 && r->ray_dir_x < 0)
		tex_x = tex_w - tex_x - 1;
	if (r->side == 1 && r->ray_dir_y > 0)
		tex_x = tex_w - tex_x - 1;
	return (tex_x);
}

int	load_textures(t_game *g)
{
	if (!load_tex(g, g->map->no_path, TEX_NO))
		return (0);
	if (!load_tex(g, g->map->so_path, TEX_SO))
		return (0);
	if (!load_tex(g, g->map->we_path, TEX_WE))
		return (0);
	if (!load_tex(g, g->map->ea_path, TEX_EA))
		return (0);
	return (1);
}
