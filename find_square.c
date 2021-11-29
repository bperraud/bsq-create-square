#include "header.h"

void find_biggest_square(t_map *map)
{
    int i;
    int square_size;

    i = 0;
    square_size = 1;
    while (i < map->nb_points && square_size <= MIN(map->line, map->col))
    {
        if (try_nsquare(*map, i, square_size) && square_size > map->best_square.size)
        {
            printf("square_size : %d\n", square_size);
            map->best_square.size = square_size;
            map->best_square.start_point = map->points[i];
            square_size++;
            i = 0;
        }
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

    // size trop grande
    if (map.points[index].x + square_size > map.line)
        return (0);
    i = 0;
    while (i < square_size)
    {
        if (is_empty_lines(map, index, square_size - 1))
            return (1);
        i++;
    }
    return (0);
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