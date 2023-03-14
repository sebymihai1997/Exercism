/*
    This program find saddle points in a matrix.
    A saddle point is when an element is grater then every element in it's row and less than or equal to every element in the column.
*/

#include "saddle_points.h"

static void append_saddle_point(saddle_point_t **target, size_t *count, size_t *capacity, size_t const row, size_t const column);

// Define the saddle_points function that finds saddle points in a matrix
saddle_points_t *saddle_points(size_t const row_count,size_t const column_count, void* matrix)
{
    //Alocate memory for the saddle_points_t struct
    saddle_points_t *result = malloc(sizeof(*result));
    if(!result)
    {
        return NULL;
    }
    //Cast he matrix pointer to a pointer-to-array type
    uint8_t (*array_matrix)[column_count]=matrix;
    size_t capacity=8;
    result->count=0;
    result->points=malloc(sizeof(*result->points)*capacity);

    // Loop over each element in the matrix
    for(size_t i=0;i<row_count;++i)
    {
        for(size_t j=0;j<column_count;++j)
        {
            // Get the value of the current element
            uint8_t value=array_matrix[i][j];
            int is_greater_or_equal_than_other_elements_in_row = 1;
            int is_lower_or_equal_than_other_elements_in_column = 1;

            // Check if value is a maximum in its row
            for(size_t k=0;k<row_count;++k)
            {
                if(value>array_matrix[k][j])
                {
                    is_lower_or_equal_than_other_elements_in_column = 0;
                    break;
                }
            }

                // Check if value is a minimum in its column
                for(size_t k=0;k<column_count;++k)
                {
                    if(value<array_matrix[i][k])
                    {
                        is_greater_or_equal_than_other_elements_in_row = 0;
                        break;
                    }
                }
                int is_saddle_point = is_greater_or_equal_than_other_elements_in_row && is_lower_or_equal_than_other_elements_in_column;
                // If the element is a saddle point, append it to the points array
                if(is_saddle_point)
                {
                        append_saddle_point(&result->points, &result->count, &capacity, i + 1, j + 1);
                }

        }
    }
    return result;
}

// Define the function for freeing the memory allocated for a saddle_points_t struct
void free_saddle_points(saddle_points_t *saddle_points)
{
    free(saddle_points->points);
    free(saddle_points);
}

// Define the static function for appending a saddle point to an array
static void append_saddle_point(saddle_point_t **target, size_t *count, size_t *capacity, size_t const row, size_t const column)
{
    // If the array is full, double its capacity and reallocate memory for the array
    if(*count+1>*capacity)
    {
        *capacity*=2;
        *target=realloc(*target,sizeof(**target)*(*capacity));
    }

    // Create a new saddle_point_t struct for the new saddle point
    saddle_point_t new_saddle_point={
        .row = row,
        .column=column,
    };
    //Append the new seddle point to the array
    (*target)[*count]=new_saddle_point;
    *count+=1;
}
