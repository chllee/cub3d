/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 14:08:32 by pang              #+#    #+#             */
/*   Updated: 2026/04/21 21:29:29 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

// print_map(map) is for debug
int	parse_map(int argc, char **argv)
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
