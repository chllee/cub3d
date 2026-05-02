/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_loading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 00:47:49 by pang              #+#    #+#             */
/*   Updated: 2026/05/02 14:16:11 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

void	render_frame(t_game *game)
{
	draw_map(game, game->map);
	draw_player(game);
}

int	game_movement(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		close_game(game);
	return (0);
}
