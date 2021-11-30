#include "header.h"

int	main()
{
	int		i;
	t_point	point;

	t_map	*map;
	map = malloc(sizeof(map));
	if (!parse("map.txt", map))
		return (0);
	printf("line= %d\n", map-> line);
	printf("col= %d\n", map-> col);
	printf("nb_points= %d\n", map-> nb_points);
	printf("symbols= %s\n", map-> symbols);
	i = -1;
	while (++i < map->nb_points)
	{
		point = map->points[i];
		printf("(%d, %d): %d\n", point.x, point.y, point.symbol);
	}
	free(map->points);
	free(map);
}
