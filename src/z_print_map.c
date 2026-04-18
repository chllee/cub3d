#include "map.h"

t_map	*print_map(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < map->row_count)
	{
		y = 0;
		while (y < map->col_count)
		{
			ft_printf("%c", map->grid[x][y]);
			y++;
		}
		ft_printf("\n");
		x++;
	}
	return (map);
}

/* int	enemy_map_validity(t_map *original_map)
{
	t_map	*map_copy;
	int		enemy_x;
	int		enemy_y;

	if (!enemy_pos(original_map, &enemy_x, &enemy_y))
		return (1);

	map_copy = copy_map(original_map);
	if (!map_copy)
		return (0);

	player_start(map_copy);
	map_copy->collect_count = original_map->collect_count;
	map_copy->collectibles = 0;
	map_copy->exit_found = 0;
	flood_fill_enemy(map_copy, map_copy->start_pos.x_pos, map_copy->start_pos.y_pos);

	if (map_copy->collectibles == map_copy->collect_count && map_copy->exit_found == 1)
	{
		free_map(map_copy);
		return (1); // Already valid
	}
	free_map(map_copy);

	// Now test every other possible position
	for (int test_x = 0; test_x < original_map->row_count; test_x++)
	{
		for (int test_y = 0; test_y < original_map->col_count; test_y++)
		{
			if (original_map->grid[test_x][test_y] != '0')
				continue;

			map_copy = copy_map(original_map);
			if (!map_copy)
				return (0);

			map_copy->grid[enemy_x][enemy_y] = '0'; // Clear old
			map_copy->grid[test_x][test_y] = 'H';   // Move enemy

			player_start(map_copy);
			map_copy->collect_count = original_map->collect_count;
			map_copy->collectibles = 0;
			map_copy->exit_found = 0;
			flood_fill_enemy(map_copy, map_copy->start_pos.x_pos, map_copy->start_pos.y_pos);

			if (map_copy->collectibles == map_copy->collect_count && map_copy->exit_found == 1)
			{
				free_map(map_copy);
				return (1); // Valid path found
			}

			free_map(map_copy);
		}
	}
	return (0); // No valid path found with any enemy position
} */

