/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 08:37:42 by chllee            #+#    #+#             */
/*   Updated: 2026/05/02 11:55:39 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../map/map.h"
#include "../mlx/image.h"

static void	start_game(t_game *game)
{
	render_frame(game);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	game;

	if (argc != 2)
		exit_error("Invalid argument");
	file_ext(argv[1]);
	map = process_file(argv[1]);
	init_game(&game, map);
	game.map = map;
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		exit_error("mlx initialisation failed");
	game.win_ptr = mlx_new_window(game.mlx_ptr,
		WIN_HEIGHT, WIN_WIDTH, "game");
	if (!game.win_ptr)
		exit_error("mlx window failed");


	start_game(&game);
	//print_map(map);
	mlx_hook(game.win_ptr, 2, KeyPressMask, game_movement, &game);
	mlx_hook(game.win_ptr, 33, 0, close_game, &game);
	mlx_loop(game.mlx_ptr);
	close_game(&game);
	return (0);
}
