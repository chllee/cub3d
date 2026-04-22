/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang < pang@student.42singapore.sg>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:18:45 by pang              #+#    #+#             */
/*   Updated: 2025/06/03 20:08:06 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif 

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "../libft01/libft.h"

char	*ft_strjoin_sub(char const *s1, char const *s2);
char	*ft_strdup_extract(const char *src);
char	*ft_substr_remain(const char *s);
char	*read_store(int fd, char *storage);
char	*get_next_line(int fd);

#endif
