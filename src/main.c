/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 14:08:32 by pang              #+#    #+#             */
/*   Updated: 2026/04/18 18:10:08 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		exit_error("Invalid argument");
	file_ext(argv[1]);
	init_map(map);
	map = process_map(argv[1]);
	// init map
	(void)map;
	
	free_map(map);
	return (0);
}
