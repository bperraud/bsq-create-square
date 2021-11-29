#include "header.h"

int	main()
{
	t_map	*map;
	map = malloc(sizeof(map));
	parse("map.txt", map);

	free(map);
}
