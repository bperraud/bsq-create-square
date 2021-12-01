#include "header.h"

void find_bsq(t_map *map)
{
    int i;
    int square_size;

    i = 0;
    square_size = 1;
    while (i < map->nb_points && square_size <= MIN(map->line, map->col))
    {
        if (try_nsquare(*map, i, square_size) && square_size > map->bsq.size)
        {
            map->bsq.size = square_size;
            map->bsq.start_point.x = map->points[i].x;
            map->bsq.start_point.y = map->points[i].y;
            map->bsq.index = i;
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
    while (i < square_size)
    {
        if (!is_no_symbol_line(map, index, square_size) || !is_index_in_map(map, index, square_size - 1)|| index >= map.nb_points)
            return (0);
        else
        {
            i++;
            index += map.line;
        }
    }
    return (1);
}