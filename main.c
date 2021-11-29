#include "header.h"

int main() {

    t_map map;

    map.best_square.size = 0;
    map.col = 4;
    map.line = 4;

    map.points = malloc( 16 * sizeof(t_point));
    int i = 0;

    printf("start\n");

    while (i < 4)
    {
        t_point point;
        int j = 0;
        while (j < 4) {
            point.x = i;
            point.y = j;
            point.symbol = 0;
            map.points[j] = point;
            j++;
        }
        i++;
    }

    find_biggest_square(map);
    printf("(x, y) : (%d, %d)\n", map.best_square.start_point.x, map.best_square.start_point.x);
    printf("%d\n", map.best_square.size);


    free(map.points);
    printf("end\n");
    return 0;
}