#include "header.h"


void bsq(t_map *map, char *path)
{

    if (!parse(path, map))
    {
        printf("soucis parsing");
        exit(EXIT_SUCCESS);
    }
    else
        printf("c'est bon");

    map->bsq.size = 0;
    map->bsq.start_point.x = -1;
    map->bsq.start_point.y = -1;
    map->bsq.index = -1;

    print_map(*map);

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
        create_map_file();
        path = ft_strdup("new_map.txt");
        bsq(map, path);
    }
    else
    {
        int i;

        i = 1;
        while (i < argc)
        {
            path = ft_strdup(argv[i]);
            bsq(map, path);
            argc--;
        }
    }
    printf("end\n");
    return 0;
}




