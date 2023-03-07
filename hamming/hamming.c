/*
    This program calculate the Hamming distance between two strings of characters.
    The Hamming distance is a measure of the difference between two strings of equal length.
    It is defined as the number of positions in the two strings where the corresponding characters are different.
*/


#include "hamming.h"


int compute(const char *lhs, const char *rhs)
{

    int DistHam=0;
    int i,len_lhs=0,len_rhs=0;

    //determinate length of lhs
    for(i=0;*(lhs+i)!='\0';i++)
    {
        len_lhs++;
    }

    //determinate length of rhs
    for(i=0;*(rhs+i)!='\0';i++)
    {
        len_rhs++;
    }

    if(*lhs=='\0'&&*rhs=='\0')
    {
        DistHam=0; //check if both strands are empty
    }
    else if(len_lhs!=len_rhs)
    {
        DistHam=-1; //check if the length of strands are different
    }
    else
    {
        for(i=0;i<len_lhs;i++)
        {
                if(*(lhs+i)!=*(rhs+i))
                {
                    DistHam++; //determinate Hamming Distance
                }
        }
    }

    return DistHam;
}
