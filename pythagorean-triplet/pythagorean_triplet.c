/*
    This program find all the Pythagorean triplets by a given sum.
    First function 'is_pythagorean_triplet' determin and determin if the triplet is Pythagorean triplet or not.
    Second function 'triplets_with_sum' find all Pythagorean triplets by a given sum.
    Third function 'free_triplets' frees the memory allocated for the struct containing the triplets.
*/

#include "pythagorean_triplet.h"

_Bool is_pythagorean_triplet(uint16_t a, uint16_t b, uint16_t c)
{
    _Bool ascending = (a < b) && (b < c); // a < b < c
    _Bool pythagorean = (a * a + b * b == c * c); // a^2+b^2=c^2
    return ascending && pythagorean;
}
triplets_t* triplets_with_sum(uint16_t sum)
{
    uint16_t a,b,c;
    triplets_t* result = malloc(sizeof(triplet_t) * sum); // Allocate memory for the struct that will store the triplets.
    result->count = 0; // Initialize the number of triplets found to zero.

    /*
        Two nested loops iterating over possible values of 'a' and 'b'.
        Knowing that 'a' < 'b' < 'c' the larger value that can be is 'sum/3'.
        Assuming the maxim value of 'c' is 'sum-a-b' then b can be the most '(sum-a)/2'.
    */

    for (a = 1; a < sum/3; a++)
    {
        for (b = a+1; b <= (sum-a)/2; b++)
        {
            c = sqrt(a*a + b*b); // Compute the value of 'c' for the current values of 'a' and 'b'.
            if (is_pythagorean_triplet(a, b, c) && a + b + c == sum)
            {
                triplet_t current = { .a = a, .b = b, .c = c };// Create a new triplet and initialize it with the values of 'a', 'b', and 'c'.
                result->triplets[result->count] = current; //Store the values in the array.
                result->count++; //Increment the number of triplets found.
            }
        }
    }

    return result; // Return a pointer to the struct containing the array of triplets and the number of triplets found.
}
void free_triplets(triplets_t* triplet)
{
    free(triplet);
    return;
}
