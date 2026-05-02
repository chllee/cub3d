/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_keyevent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 23:23:43 by pang              #+#    #+#             */
/*   Updated: 2026/05/02 14:14:27 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

int	close_game(t_game *game)
{
	ft_putstr_fd("We are sad to see you go!\n", 1);
	free_map_resources(game->map);
	free_game_resources(game);
	exit(EXIT_SUCCESS);
	return (0);
}
