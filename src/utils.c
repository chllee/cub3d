/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 17:24:34 by pang              #+#    #+#             */
/*   Updated: 2026/04/19 19:42:38 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

char	*skip_whitespace(char *str)
{
	while (str && (*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	return (str);
}

bool	empty_line(const char *line)
{
	if (!line)
		return (true);
	while (*line)
	{
		if (!(*line == ' ' || (*line >= 7 && *line <= 13)))
			return (false);
		line++;
	}
	return (true);
}

bool	is_mapline(char *line)
{
	return (line[0] == '1' || line[0] == '0' || line[0] == ' ');
}
