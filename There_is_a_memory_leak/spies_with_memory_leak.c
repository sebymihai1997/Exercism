#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char *question;
    struct node *no;
    struct node *yes;
}node;

// Function to get yes/no answer from the user
int yes_no(char *question)
{
    char answer[3];
    printf("%s? (y/n): ",question);
    fgets(answer,3,stdin);
    return answer[0] == 'y';
}

// Function to create a new node in the decision tree
node* create(char *question)
{
    node *n = malloc(sizeof(node));
    n->question = strdup(question);
    n->no = NULL;
    n->yes = NULL;
    return n;
}

// Function to release the memory allocated for the decision tree
void release(node *n)
{
    if(n)
    {
        if(n->no)
            release(n->no);
        if (n->yes)
        {
            release(n->yes);
        }
        if (n->question)
        {
            free(n->question);
        }
        free(n);
    }
}

int main(void)
{
    char question[80];
    char suspect[20];

    // Creating the initial nodes of the decision tree
    node *start_node = create("Does suspect have a mustache");
    start_node->no = create("Loretta Barnsworth");
    start_node->yes = create("Vinny the Spoon");

    node *current;
    do
    {
        current = start_node;
        while (1)
        {
            if (yes_no(current->question))
            {
                if (current->yes)
                {
                    current = current->yes;
                }
                else
                {
                    printf("SUSPECT IDENTIFIED\n");
                    break;
                }
            }
            else if (current->no)
            {
                current = current->no;
            }
            else
            {
                printf("Who's the suspect? ");
                fgets(suspect,20,stdin);

                // Create new nodes for the suspect
                node *yes_node = create(suspect);
                current->yes = yes_node;

                node *no_node = create(current->question);
                current->no = no_node;

                printf("Give me a question that is TRUE fo %s but not for %s?",suspect,current->question);
                fgets(question,80,stdin);

                // Update the current node's question
		        /*
                Before assigning a new question to current->question, the code needs to free the memory allocated for the previous question. 
                This prevents memory leaks and ensures efficient memory management.
                free(current->question);
                */
                current->question = strdup(question);

                break;
            }



        }

    } while (yes_no("Run again"));
    // Release the memory allocated for the decision tree
    release(start_node);
    return 0;
}
