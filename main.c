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


int main() {

    t_map map;

    map.bsq.size = 0;
    map.bsq.start_point->x = -1;
    map.bsq.start_point->y = -1;
    map.bsq.index = -1;
    map.nb_points = 16;
    map.col = 4;
    map.line = 4;
    map.symbols[0] = '.';
    map.symbols[1] = 'x';
    map.symbols[2] = 'o';
    map.points = malloc( 16 * sizeof(t_point));

    int i = 0;
    while (i < 4)
    {
        int j = 0;
        while (j < 4) {
            t_point point;
            point.x = i;
            point.y = j;
            point.symbol = 0;
            map.points[i * map.line + j] = point;
            j++;
        }
        i++;
    }

    map.points[2].symbol = 2;
    map.points[5].symbol = 2;
    map.points[7].symbol = 2;
    map.points[9].symbol = 2;
    map.points[14].symbol = 2;

    print_map(map);

    printf("no symbol line %d\n", is_no_symbol_line(map, 13, 1));
    printf(" is_index_in_map %d\n", is_index_in_map(map, 6, 2));
    //printf("empty lines %d\n", is_empty_lines(map, 6, 2));

    find_bsq(&map);
    printf("try square(0, 2) :  %d\n", try_nsquare(map, 0, 2));

    printf("(x, y) : (%d, %d)\n", map.bsq.start_point->x, map.bsq.start_point->y);
    printf("size bsq : %d\n", map.bsq.size);
    printf("index bsq : %d\n", map.bsq.index);

    write_bsq(map);
    print_map(map);

    free(map.points);
    printf("end\n");
    return 0;
}
