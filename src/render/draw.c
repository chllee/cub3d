/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 00:00:00 by chllee            #+#    #+#             */
/*   Updated: 2026/05/10 00:00:00 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_pixel(t_img *screen, int x, int y, int color)
{
	char	*dst;

	dst = screen->addr + (y * screen->line_len + x * (screen->bpp / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

static int	get_tex_color(t_tex *tex, int tx, int ty)
{
	char	*src;

	if (tx < 0)
		tx = 0;
	if (ty < 0)
		ty = 0;
	if (tx >= tex->width)
		tx = tex->width - 1;
	if (ty >= tex->height)
		ty = tex->height - 1;
	src = tex->addr + (ty * tex->line_len + tx * (tex->bpp / 8));
	return (*(int *)src);
}

void	draw_bg(t_game *g, t_wall *w)
{
	int	y;

	y = 0;
	while (y < w->top)
	{
		put_pixel(&g->screen, w->x, y, (int)g->map->c_hex);
		y++;
	}
	y = w->bot + 1;
	while (y < WIN_H)
	{
		put_pixel(&g->screen, w->x, y, (int)g->map->f_hex);
		y++;
	}
}

void	draw_wall(t_game *g, t_ray *r, t_wall *w)
{
	t_tex	*tex;
	int		tex_x;
	int		tex_y;
	int		line_h;
	int		y;

	tex = &g->tex[get_tex_idx(r)];
	tex_x = get_tex_x(r, &g->player, tex->width);
	line_h = w->bot - w->top;
	y = w->top;
	while (y <= w->bot)
	{
		tex_y = ((y - w->top) * tex->height) / (line_h + 1);
		put_pixel(&g->screen, w->x, y, get_tex_color(tex, tex_x, tex_y));
		y++;
	}
}
