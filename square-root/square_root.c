/*
    This program calculates the square root of an integer number.
*/


#include "square_root.h"

float square_root(int number)
{
    float sqrt,temp;

    // If the number is 1, the square root is 1
    if(number==1)
    {
        sqrt=1;
    }
    else
    {
        // Initial approximation of the square root
        sqrt=number/2;
        temp=0;

        // Use the Babylonian method to refine the approximation
        while(sqrt!=temp)
        {
            temp=sqrt;

            sqrt=(number/temp+temp)/2;
        }
    }


    return sqrt;
}
