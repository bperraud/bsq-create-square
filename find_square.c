#include "header.h"





t_point* find_biggest_square(t_map map)
{




}



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


