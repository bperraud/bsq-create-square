#include "header.h"

void bsq(t_map *map, char *path)
{
    if (!parse(path, map))
    {
        printf("soucis parsing");
        exit(EXIT_SUCCESS);
    }
    map->bsq.size = 0;
    map->bsq.start_point.x = -1;
    map->bsq.start_point.y = -1;
    map->bsq.index = -1;

    print_map(*map);

    printf("\n");

    find_bsq(map);
    write_bsq(*map);

    print_map(*map);
    free(map->points);
    free(map);
}

int main(int argc, char **argv) {

    char *path;
    t_map *map;

    map = malloc(sizeof(*map));
    if (argc == 1) {
        standard_input_map(1);
        path = ft_strdup("new_map.txt");
        if (!parse(path, map))
            return (0);
        bsq(map, path);
    }
    else
    {
        int i;

        i = 1;
        while (i < argc)
        {
            path = ft_strdup(argv[i]);
            if (!parse(path, map))
                return (0);
            bsq(map, path);
            write(1, "\n", 1);
            argc--;
        }
    }

    printf("END");

    return 0;
}




