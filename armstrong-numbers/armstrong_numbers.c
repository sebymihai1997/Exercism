/*
 This program determin if a number is an Armstrong number.
 An Armstrong number is a number that is equal to the sum of its own digits raised to the power of the number of digits.
*/
#include "armstrong_numbers.h"

bool is_armstrong_number(int candidate){

    int number,module,result,power,digit_count;
    int i,k;
    int digit[8];

    number=candidate;
    i=0;
    result=0;


    // Separate the numberber into digitits

    // Whille number is bigger than 0
    do{
        module=number%10; // separate the last digit from the number
        digit[i]=module; // store the last digit
        i++;
        number=number/10; // divide by 10 to separete the remaining digits from the last one
        digit_count=i;
    }while(number > 0);

    // Loop that calculate the sum on digitis to the power of digit_count
    for(i=0;i<digit_count;i++)
    {
        power=digit[i]; // digit[0]^1

        for(k=1;k<digit_count;k++)
        {
    //Raising digit to the power of k excluding power of 1
            power=power*digit[i];
        }

    //Sum the digit after they are reised to the power of digit_count
        result+=power;
    }

    return result==candidate;
}
