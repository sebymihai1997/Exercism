/*
    This code provides a way to handle different types of responses using function pointers and a dispatch table, 
    making it easy to add new response types and associate them with corresponding functions.
*/
#include <stdio.h>

// Enum defining different response types
enum response_type {DUMP, SECOND_CHANCE, MARRIAGE};

typedef struct {
    char *name;
    enum response_type type;
} response;

// Function to handle a dump response
void dump(response r)
{
    printf("Dear %s,\n", r.name);
    puts("Unfortunately your last date contacted us to");
    puts("say that they will not be seeing you again");
}

// Function to handle a second chance response
void second_chance(response r)
{
    printf("Dear %s,\n", r.name);
    puts("Good news: your last date has asked us to");
    puts("arrange another meeting. Please call ASAP.");
}

// Function to handle a marriage response
void marriage(response r)
{
    printf("Dear %s,\n", r.name);
    puts("Congratulations! Your last date has contacted");
    puts("us with a proposal of marriage.");
}

// Array of function pointers for different response types
void (*replies[])(response) = {dump,second_chance,marriage};

int main()
{
    // Array of response structs
    response r[] = {
        {"Mike", DUMP}, {"Luis", SECOND_CHANCE},
        {"Matt", SECOND_CHANCE}, {"William", MARRIAGE}
    };
    int i;
    for (i = 0; i < 4; i++) {
        // Call the appropriate function based on the response type
        replies[r[i].type](r[i]);
    }
    return 0;
}