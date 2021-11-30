#include "header.h"

void print_map(t_map map)
{
    int i;
    int j;

    i = 0;
    while (i < map.line)
    {
        j = 0;
        while (j < map.col)
        {
            write(1,  &map.symbols[map.points[i * map.line + j].symbol], 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}

/*
 * return 1 if there are "lines" empty lines from start point
 */
int is_empty_lines(t_map map, int index, int lines)
{
    int i;

    i = 0;
    while (i <= lines)
    {
        if (!is_no_symbol_line(map, index, lines) || !is_index_in_map(map, index, lines) || map.points[index].symbol == 2 || index >= map.nb_points)
        {
            printf("pas possible\n");
            return (0);
        }
        else
        {
            i++;
            index += map.line;
        }
    }
    return (1);
}

/*
 * return 1 if the line starting at index is empty for nb symbol to the right, else 0
 * only check for obstacle
 */
int is_no_symbol_line(t_map map, int index, int nb)
{
    int max ;

    max = index + nb;
    while (index <= max)
    {
        if (map.points[index].symbol == 2)
            return (0);
        index++;
    }
    return (1);
}

/*
 * return the maximum value possible for an index on the same line
 */
int is_index_in_map(t_map map, int index, int size)
{
    if (map.points[index].y + size > map.line - 1)
    {
        //printf("depasse la map\n");
        return (0);
    }
    return (1);
}