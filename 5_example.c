#include <stdio.h>
#include <stdlib.h>
#include <string.h> //include was missing

#define CAPACITY 25

void text_printer(char *msg); //function declaration was missing

int main(void)
{
    char *buffer;
    buffer = malloc(CAPACITY * sizeof(char));
    strcpy(buffer, "Some random text");
    text_printer(buffer);
    free(buffer);
    return 0;
}

void text_printer(char *msg)
{
    printf("%s\n", msg);
    //free(msg); free is already used in main 
}