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
int is_empty_line(t_map map, int index, int nb);
int is_empty_lines(t_map map, int index, int lines);

//find_square
void find_biggest_square(t_map map);
int try_nsquare(t_map map, int index, int size);

//string operations
char	**ft_split(char *str, char *charset);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_atoi(char *str);
void	ft_putstr(char *str);
char    *ft_strdup(char *src);
int		list_len(char **list);

//file parsing function
int parse(char *path, t_map *map);
int	check_map(char **split);

//create map file
void create_file_map();

#endif
