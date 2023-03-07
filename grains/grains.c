/*
    This program calculate the number of grains of wheat on a chess board.

    There once was a wise servant who saved the life of a prince.
    The king promised to pay whatever the servant could dream up.
    Knowing that the king loved chess, the servant told the king he would like to have grains of wheat.
    One grain on the first square of a chess board, with the number of grains doubling on each successive square.
*/

#include "grains.h"
//Calculate the number of grains on a given square.
uint64_t square(uint8_t index)
{
    int i;
    long long x[63];
    long long grain;

    x[0]=1;
    //Check if the chess square is valid.
    if(index==0||index>64)
    {
        grain=0;
    }
    //Initialize the first square with 1.
    else if(index==1)
    {
        grain=1;
    }
    else
        //Calculate the number of grains on the given square.
        for(i=1;i<index;i++)
        {
            x[i]=x[i-1]*2;//Calculating the number of grains on each square based on the previous square, which has twice as many grains.
            grain=x[i];
        }
    //Return the number of grains on that square.
    return grain;
}

//Calculate the total number of grains on the chessboard.
uint64_t total(void)
{
    int i;
    long double x[65];
    long double totalGrains=1;

    x[0]=1;

    for(i=1;i<64;i++)
    {
        x[i]=x[i-1]*2; //Calculating the number of grains on each square based on the previous square, which has twice as many grains.
        totalGrains=totalGrains+x[i];//Adds the number of grains on each square to totalGrain.
    }
    //Return the total number of grains of wheat on the entire chessboard.
    return totalGrains;
}
