/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 08:37:42 by chllee            #+#    #+#             */
/*   Updated: 2026/04/27 07:09:39 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../map/map.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		exit_error("Invalid argument");
	file_ext(argv[1]);
	map = process_file(argv[1]);
	print_map(map);
	free_resources(map);
	return (0);
}