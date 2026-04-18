

#include "cub3d.h"

void	exit_error(char *msg)
{
	ft_printf("Error: %s\n", msg);
	exit(EXIT_FAILURE);
}

// Check for file extension
void	file_ext(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		exit_error("Filename invalid");
	if (ft_strcmp((filename + len - 4), ".cub") != 0)
		exit_error("Invalid filename extension");
}
