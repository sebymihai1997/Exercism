#ifndef SADDLE_POINTS_H
#define SADDLE_POINTS_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int row;
    int column;
}saddle_point_t;

typedef struct{
    size_t count;
    saddle_point_t *points;
}saddle_points_t;

saddle_points_t *saddle_points(size_t const row_count,size_t const column_count, void* matrix);
void free_saddle_points(saddle_points_t *saddle_points);



#endif
