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
//    printf("index in map 12, 2 %d\n", is_index_in_map(*map, 12, 4 - 1));
//    printf("index in map 17, 2 %d\n", is_index_in_map(*map, 17, 3 - 1));
//    printf("index in map 22, 2 %d\n", is_index_in_map(*map, 22, 3 - 1));
//
//    printf(" is_no_symbol_line : %d\n", is_no_symbol_line(*map, 12, 3));
//    printf(" is_no_symbol_line : %d\n", is_no_symbol_line(*map, 17, 3));
//    printf(" is_no_symbol_line : %d\n", is_no_symbol_line(*map, 22, 3));
//    printf(" is_no_symbol_line : %d\n", is_no_symbol_line(*map, 0, 2));
//    printf(" is_no_symbol_line : %d\n", is_no_symbol_line(*map, 4, 2 - 1));
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
            write(1, "\n", 1);
            argc--;
        }
    }
    return 0;
}




