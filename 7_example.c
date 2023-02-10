#include <stdio.h>
#include <stdlib.h>
#include <string.h> //include was missing

#define SIZE 44

void mem_alloc(char **buffer) //to change the value of pointer in function we need to pass a pointer to pointer
{
    *buffer = malloc(SIZE * sizeof(char));
}

int main(void)
{
    char *buffer = NULL;
    mem_alloc(&buffer); //since I changed the function parameters now we need to pass the address of buffer
    strcpy(buffer, "Some random text to be copied to the buffer");
    printf("%s\n", buffer);
    free(buffer);
    return 0;
}