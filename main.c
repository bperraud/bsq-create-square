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

//    printf("try 0, 1 %d\n", try_nsquare(*map, 0, 1));
//    printf("try 0 ,2 %d\n", try_nsquare(*map, 0, 2));
//
//    printf(" is_no_symbol_line : %d\n", is_no_symbol_line(*map, 0, 1));
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
            argc--;
        }
    }
    printf("end\n");
    return 0;
}




