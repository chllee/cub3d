/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pang <pang@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 00:03:40 by pang              #+#    #+#             */
/*   Updated: 2025/05/19 00:03:40 by pang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* #include <fcntl.h>     // for open
#include <unistd.h>    // for write, close
#include <stdio.h>     // for perror

int	main(void)
{
	// 1. ✅ Normal case: print to standard output
	ft_putchar_fd('A', 1); // should print 'A' to the terminal
	write(1, "\n", 1);

	// 2. 🔁 Edge case: print newline and non-printable ASCII
	ft_putchar_fd('\n', 1);  // newline
	ft_putchar_fd(7, 1);     // ASCII bell sound (may not be visible)

	// 3. 🛑 Special case: invalid fd
	ft_putchar_fd('X', -1); // should fail silently or do nothing

	// 4. 📝 File test: print to file
	int file = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1)
	{
		perror("Failed to open file");
		return (1);
	}
	ft_putchar_fd('F', file);
	ft_putchar_fd('D', file);
	ft_putchar_fd('\n', file);
	close(file);

	// 5. 🧪 Repeated use
	for (char ch = 'a'; ch <= 'z'; ch++)
		ft_putchar_fd(ch, 1);
	write(1, "\n", 1);

	return (0);
}
 */