#include "header.h"

int bsq(char *path)
{
	t_map	*map;

    map = malloc(sizeof(*map));
	if (!map)
		return (0);
    if (!parse(path, map))
    {
        printf("soucis parsing");
        exit(EXIT_SUCCESS);
    }
    map->bsq.size = 0;
    map->bsq.start_point.x = -1;
    map->bsq.start_point.y = -1;
    map->bsq.index = -1;

    printf("(line, col) (%d, %d)\n", map->line, map->col);

    print_map(*map);
    printf("\n");
    find_bsq(map);
    write_bsq(*map);

    print_map(*map);
    free(map->points);
    free(map);
	return (1);
}

int main(int argc, char **argv)
{
    char *path;

    if (argc == 1) {
        standard_input_map(1);
        path = ft_strdup("new_map.txt");
		if (!path)
			return (0);
        if (!bsq(path))
			return (0);
		free(path);
    }
    else
    {
        int i;

        i = 1;
        while (i < argc)
        {
            path = ft_strdup(argv[i]);
			if (!path)
				return (0);
            if (!bsq(path))
				return (0);
            write(1, "\n", 1);
			i++;
			printf("%s\n", path);
			free(path);
        }
    }
    printf("END\n");
    return 0;
}
