#include "header.h"

void find_biggest_square(t_map map)
{
    int i;
    int size;

    i = 0;
    size = 1;
    while (i < map.line * map.col && size <= MIN(map.line, map.col))
    {
        if (try_nsquare(map, i, size))
        {
            map.best_square.size = size;
            map.best_square.start_point = map.points[i];
            size++;
            i = 0;
        }
        i++;
    }
}


/*
 * try to create a square of size n at point index
 * return 1 if it is possible, else 0
 */
int try_nsquare(t_map map, int index, int size)
{
    int i;

    if (map.points[index].x + size > map.line)
        return (0);
    i = 0;
    while (i < size)
    {
        if (is_empty_lines(map, index, size))
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