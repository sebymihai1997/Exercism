#include "difference_of_squares.h"

/*
    This program calculates the difference between the square of the sum and the sum of squares.
*/


//Initialize the array
unsigned int *init_array(unsigned int number)
{
    static unsigned int x[101];
    int i;

    x[0]=1;

    //intialization of the array
    for(i=1;i<number;i++)
    {
        x[i]=x[i-1]+1;
    }

    return x;
}

// Calculate the sum of the squares of the first "number" positive integers
unsigned int sum_of_squares(unsigned int number)
{
    unsigned int *x;
    int i,sum;


    sum=0;

    x=init_array(number);
    //calculate the sum of squares
    for(i=0;i<number;i++)
    {
        sum+=*(x+i)**(x+i);// Add the square of each integer to the sum
    }

    return sum;
}

// Calculate the square of the sum of the first "number" positive integers
unsigned int square_of_sum(unsigned int number)
{

    unsigned int *x;
    int i,sum;

    sum=0;

    x=init_array(number);
    //calculate the sum of the numbers
    for(i=0;i<number;i++)
    {
        sum+=*(x+i); // Add each integer to the sum

    }
    sum*=sum; // calculate the square of the sum

    return sum;
}

// Calculate the difference between the square of the sum and the sum of squares of the first "number" positive integers
unsigned int difference_of_squares(unsigned int number)
{
    int dif;

    //difference between square of sum and sum of square
    dif=square_of_sum(number)-sum_of_squares(number);

    return dif;
}
