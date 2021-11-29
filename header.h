#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>

typedef struct s_point
{
    int	x;
    int	y;
    int symbol; //0 vide 1 plein 2 obstacle
}   t_point;


typedef struct s_square
{
    t_point start_point;
    t_point end_point;
    int size;
} t_square;


typedef struct s_map
{
    t_point *points;
    int width;
    int lenght;
    int nb_points;
    char symbols[3];   // 3 indices
    t_square best_square;
} t_map;



//functions
int is_empty_line(t_map map, t_point point, int lines);
int is_empty_lines(t_map map, t_point start_point, int lines);

#endif
