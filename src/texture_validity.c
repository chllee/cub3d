/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_validity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 17:15:28 by pang              #+#    #+#             */
/*   Updated: 2026/04/21 21:28:45 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	valid_path(char *path, t_map *map)
{
	int	fd;
	int	len;

	if (!path)
		freealloc_exit(map, "Missing texture path");
	len = ft_strlen(path);
	if (len < 5 || ft_strncmp(&path[len - 4], ".xpm", 4) != 0)
		freealloc_exit(map, "Texture not an .xpm file");
	fd = open(path, O_RDONLY);
	if (fd == -1)
		freealloc_exit(map, "Cannot open texture file");
	close(fd);
}

static int	str_is_digit(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (!str[i])
		return (0);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	while (str[i] && ft_isspace(str[i]))
		i++;
	return (str[i] == '\0');
}

static void	check_colour_range(char **rgb, t_map *map)
{
	int	i;
	int	num;

	i = 0;
	while (rgb[i])
	{
		if (!str_is_digit(rgb[i]))
		{
			free_split(rgb);
			freealloc_exit(map, "Colour contains non-digits");
		}
		num = ft_atoi(rgb[i]);
		if (num < 0 || num > 255)
		{
			free_split(rgb);
			freealloc_exit(map, "Colour value out of range");
		}
		i++;
	}
	if (i != 3)
	{
		free_split(rgb);
		freealloc_exit(map, "Invalid colour format");
	}
}

// check for commas, check all digits, between 0-255, parse them individually
void	valid_colours(char *str, t_map *map)
{
	int		comma_count;
	int		i;
	char	**rgb;

	comma_count = 0;
	i = 0;
	if (!str)
		freealloc_exit(map, "Missing colour information");
	while (str[i])
	{
		if (str[i] == ',')
			comma_count++;
		i++;
	}
	if (comma_count != 2)
		freealloc_exit(map, "Invalid colour format");
	rgb = ft_split(str, ',');
	if (!rgb)
		freealloc_exit(map, "Colour split fail");
	check_colour_range(rgb, map);
	free_split(rgb);
}
