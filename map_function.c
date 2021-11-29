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
    while (i < lines)
    {
        if (!is_empty_line(map, index, i))
            return (0);
        else
        {
            i++;
            index += map.line;
        }
    }
    return (1);
}

/*
 * return 1 if the line of start_point is empty for size char
 */
int is_empty_line(t_map map, int index, int nb)
{
    while (index < nb)
    {
        if (map.points[index].symbol == 2)
            return (0);
        index++;
    }
    return (1);
}