#include "map.h"

t_map   *print_map(t_map *map)
{
    int y;

    if (!map || !map->grid)
    {
        ft_printf("No map grid to print.\n");
        return (map);
    }
    y = 0;
    ft_printf("--- START OF GRID ---\n");
    while (y < map->y_max)
    {
        ft_printf("%s\n", map->grid[y]);
        y++;
    }
    ft_printf("--- END OF GRID ---\n");
    ft_printf("Dimensions: y_max: %d, x_max: %d\n", map->y_max, map->x_max);
	ft_printf("process_file\nNO: %s\nSO: %s\nWE: %s\nEA: %s\nF: %s\nC: %s\n", map->no_path, map->so_path, map->we_path, map->ea_path, map->f_path, map->c_path);
	ft_printf("Process_file, map->texture_count: %d\n", map->texture_count);
	ft_printf("f_hex: %d\n", map->f_hex);
	ft_printf("c_hex: %d\n", map->c_hex);
    return (map);
}

