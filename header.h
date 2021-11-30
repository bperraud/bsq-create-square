#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

typedef struct s_point
{
    int	x;
    int	y;
    int symbol; //0 vide ; 1 plein ; 2 obstacle
}   t_point;

typedef struct s_square
{
    t_point *start_point;
    int index;
    int size;
} t_square;

typedef struct s_map
{
    t_point *points;
    int line;
    int col;
    int nb_points;
    char symbols[3];   // 3 indices
    t_square bsq;
} t_map;

//map function
int is_no_symbol_line(t_map map, int index, int nb);
void print_map(t_map map);
int is_index_in_map(t_map map, int index, int size);
void write_line(t_map map, int index);
void write_bsq(t_map map);

//find_square
void find_bsq(t_map *map);
int try_nsquare(t_map map, int index, int size);

//string operations
char	**ft_split(char *str, char *charset);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_atoi(char *str);

//file parsing function
int 	parse(char *path, t_map *map);

#endif
