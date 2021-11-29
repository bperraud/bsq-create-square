#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>

typedef struct s_point
{
    int	x;
    int	y;
    int symbol; //0 vide 1 plein 2 obstacle
}   t_point;

typedef struct s_map
{
    t_point *points;
    int width;
    int lenght;
    int nb_points;
    char symbols[3];   // 3 indices
} t_map;


#endif
