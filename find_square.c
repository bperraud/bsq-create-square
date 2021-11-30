#include "header.h"

void find_biggest_square(t_map *map)
{
    int i;
    int square_size;

    i = 0;
    square_size = 1;
    while (i < map->nb_points && square_size <= MIN(map->line, map->col))
    {
//        printf("i : %d\n", i);
//        printf("square_size : %d\n", square_size);
        if (try_nsquare(*map, i, square_size)) // && square_size >= map->best_square.size)
        {
            printf("index : %d, meilleur solution : %d \n", i, square_size);
            printf("x : %d, y : %d \n", map->points[i].x, map->points[i].y);
            map->best_square.size = square_size;
            map->best_square.start_point->x = map->points[i].x;
            map->best_square.start_point->y = map->points[i].y;
            square_size++;
            i = 0;
        }
        else
            i++;
    }
}

/*
 * try to create a square of size n at point index
 * return 1 if it is possible, else 0
 */
int try_nsquare(t_map map, int index, int square_size)
{
    int i;

    i = 0;
    while (i <= square_size - 1)
    {
        if (!is_no_symbol_line(map, index, square_size - 1) || !is_index_in_map(map, index, square_size - 1) || map.points[index].symbol == 2 || index >= map.nb_points)
            return (0);
        else
        {
            i++;
            index += map.line;
        }
    }
    return (1);
}

/*
 * get point with coordinate (x, y)
 */
t_point get_point(t_map map, int x, int y)
{
    int i;

    i = 0;
    while(i < map.nb_points)
    {
        if (map.points[i].x == x && map.points[i].y == y)
            return map.points[i];
    }
    return map.points[0];
}