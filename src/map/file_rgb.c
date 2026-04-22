/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 21:24:07 by pang              #+#    #+#             */
/*   Updated: 2026/04/21 21:26:14 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	rgb_conversion(char *str, int *rgb_arr)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(str, ',');
	while (i < 3)
	{
		rgb_arr[i] = ft_atoi(split[i]);
		i++;
	}
	free_split(split);
}

void	hex_colours(t_map *map)
{
	rgb_conversion(map->f_path, map->f_rgb);
	rgb_conversion(map->c_path, map->c_rgb);
	map->f_hex = (map->f_rgb[0] << 16) | (map->f_rgb[1] << 8) | map->f_rgb[2];
	map->c_hex = (map->c_rgb[0] << 16) | (map->c_rgb[1] << 8) | map->c_rgb[2];
}
