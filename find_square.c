#include <stdbool.h>
#include "header.h"


t_point* find_biggest_square(t_map map)
{
    t_point point;


}


/*
 * return 1 if there are "lines" empty lines from start point
 */
int is_empty_lines(t_map map, t_point start_point, int lines)
{
    int i;

    i = 0;
    while (i < lines)
    {
        if (!is_empty_line(map, start_point, lines))
            return (0);
        else
            i++;
    }
    return (1);
}

/*
 * return 1 if the line of start_point is empty for size char
 */
int is_empty_line(t_map map, t_point point, int nb_symbol)
{
    int i;

    i = 0;
    while (i < nb_symbol)
    {

    }

}


/*
 * try to create a square of size 1 at start_point
 */
int try_nsquare(t_map map, t_point start_point, int n)
{
    int i;

    i = 0;
    while( i < n)
    {
        if (is_empty_lines(map, start_point, n))

        i++;
    }
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

/*
 * get index in tab of points of map of the point in parameter
 */
int get_point_index(t_map map, t_point to_find_point)
{
    return -1;
}


