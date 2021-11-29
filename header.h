#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

typedef struct s_point
{
    int	x;
    int	y;
    int symbol; //0 vide ; 1 plein ; 2 obstacle
}   t_point;

typedef struct s_square
{
    t_point start_point;
    int size;
} t_square;

typedef struct s_map
{
    t_point *points;
    int line;
    int col;
    int nb_points;
    char symbols[3];   // 3 indices
    t_square best_square;
} t_map;

//map function
int is_no_symbol_line(t_map map, int index, int nb);
//int is_empty_lines(t_map map, int index, int lines);
void print_map(t_map map);
int is_index_in_map(t_map map, int index, int size);


//find_square
void find_biggest_square(t_map *map);
int try_nsquare(t_map map, int index, int size);

#endif
