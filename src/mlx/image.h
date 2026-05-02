/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 23:05:03 by pang              #+#    #+#             */
/*   Updated: 2026/05/02 14:16:00 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "map.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define WIN_HEIGHT 1280
# define WIN_WIDTH 720
# define TILE_SIZE 32
# define PI 3.14159
# define RADIUS 16

typedef	struct s_player
{
	double	pos_x;	// player pos_x
	double	pos_y;	// player pos_y
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef	struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		*map;
	t_player	player;
}	t_game;

// img_utils.c
void	free_game_resources(t_game *game);

// image_keyevent.c
int	close_game(t_game *game);

// draw_map.c
void	draw_map(t_game *game, t_map *map);
void	draw_player(t_game *game);

// init_game.c
void	init_game(t_game *game, t_map *map);

// img_loading.c
void	render_frame(t_game *game);
int	game_movement(int keycode, t_game *game);

#endif