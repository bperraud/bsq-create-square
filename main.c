#include "header.h"

int main() {

    t_map map;

    map.best_square.size = 0;
    map.best_square.start_point->x = -1;
    map.best_square.start_point->y = -1;
    map.nb_points = 16;
    map.col = 4;
    map.line = 4;
    map.symbols[0] = '.';
    map.symbols[1] = 'x';
    map.symbols[2] = 'o';
    map.points = malloc( 16 * sizeof(t_point));

    int i = 0;
    while (i < 4)
    {
        int j = 0;
        while (j < 4) {
            t_point point;
            point.x = i;
            point.y = j;
            point.symbol = 0;
            map.points[i * map.line + j] = point;
            j++;
        }
        i++;
    }

    map.points[2].symbol = 2;
    //map.points[5].symbol = 2;
    map.points[9].symbol = 2;
    map.points[14].symbol = 2;

    print_map(map);

    printf("no symbol line %d\n", is_no_symbol_line(map, 13, 1));
    printf(" is_index_in_map %d\n", is_index_in_map(map, 6, 2));
    //printf("empty lines %d\n", is_empty_lines(map, 6, 2));

    find_biggest_square(&map);

    printf("try square(0, 2) :  %d\n", try_nsquare(map, 0, 2));
    printf("(x, y) : (%d, %d)\n", map.best_square.start_point->x, map.best_square.start_point->y);
    printf("%d\n", map.best_square.size);

    free(map.points);
    printf("end\n");
    return 0;
}