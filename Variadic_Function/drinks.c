/*
    In this program I've learnd about variadic function and how can I use them.
    The code demonstrates the use of a variadic function, which is a function that can accept a variable number of arguments.
*/

#include <stdio.h>
#include <stdarg.h>

// Enum defining different drink options
enum drink {
    MUDSLIDE, FUZZY_NAVEL, MONKEY_GLAND, ZOMBIE
};

// Function to return the price of a given drink
double price(enum drink d)
{
    switch(d) {
    case MUDSLIDE:
        return 6.79;
    case FUZZY_NAVEL:
        return 5.31;
    case MONKEY_GLAND:
        return 4.82;
    case ZOMBIE:
        return 5.89;
    }
    return 0;
}

// Function to calculate the total price of variable number of drinks
double total(int args,...)
{
    double total = 0;
    va_list ap; // va_list to hold the variable arguments
    va_start(ap,args); // Initializing the va_list with the last known named argument (args)
    
    int i;

    for (i = 0; i < args; i++)
    {
        total+=price(va_arg(ap,enum drink));// Accessing the next argument of type enum drink using va_arg
    }
    
    va_end(ap); // Clean up the va_list after use
    return total;
}

int main()
{
    printf("Price is %.2f\n", total(2, MONKEY_GLAND, MUDSLIDE));
    printf("Price is %.2f\n", total(3, MONKEY_GLAND, MUDSLIDE, FUZZY_NAVEL));
    printf("Price is %.2f\n", total(1, ZOMBIE));
    
    return 0;
}