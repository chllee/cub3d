/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:18:11 by pang              #+#    #+#             */
/*   Updated: 2025/06/03 20:44:18 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_store(int fd, char *storage)
{
	char	*buffer;
	ssize_t	bytes_read;
	char	*tmp;

	if (BUFFER_SIZE == 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(storage, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin_sub(storage, buffer);
		free(storage);
		storage = tmp;
		if (!storage)
			return (free(buffer), NULL);
	}
	free (buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	char		*tmp;

	if (fd < 0)
		return (NULL);
	if (BUFFER_SIZE <= 0)
		return (NULL);
	storage = read_store(fd, storage);
	if (!storage || !*storage)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	line = ft_strdup_extract(storage);
	tmp = storage;
	storage = ft_substr_remain(tmp);
	free(tmp);
	return (line);
}
