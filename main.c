#include "header.h"

//<<<<<<< HEAD
//int	main()
//{
//	int		i;
//	t_point	point;
//
//	t_map	*map;
//	map = malloc(sizeof(map));
//	if (!parse("map.txt", map))
//		return (0);
//	printf("line= %d\n", map-> line);
//	printf("col= %d\n", map-> col);
//	printf("nb_points= %d\n", map-> nb_points);
//	printf("symbols= %s\n", map-> symbols);
//	i = -1;
//	while (++i < map->nb_points)
//	{
//		point = map->points[i];
//		printf("(%d, %d): %d\n", point.x, point.y, point.symbol);
//	}
//	free(map->points);
//	free(map);
//}
//=======




int main(int argc, char **argv) {

    if (argc == 1)
    {
        create_file_map();
    }


//    t_map	*map;
//    map = malloc(sizeof(*map));
//
//    if (!parse("map.txt", map))
//    {
//        printf("soucis parsing");
//        return (0);
//    }
//    else
//        printf("ici");
//
//    map->bsq.size = 0;

//    map->bsq.start_point->x = -1;
//    map->bsq.start_point->y = -1;
//
//    map->bsq.index = -1;
//
//    print_map(*map);

//    find_bsq(map);
//
//    write_bsq(*map);
//    print_map(*map);
//
//    free(map->points);
//    free(map);

    printf("end\n");
    return 0;
}

