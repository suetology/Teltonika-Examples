#include <stdio.h>
#include <stdlib.h> //includes were missing
#include <string.h> 

#define SIZE 17

int main(void)
{
    char *buffer;
    //buffer = malloc(15); 15 bytes may be not enough
    buffer = malloc(SIZE * sizeof(char));
    strcpy(buffer, "Some random text");
    printf("%s\n", buffer);
    free(buffer); //after using malloc you need to free the memory
    return 0;
}