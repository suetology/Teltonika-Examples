#include <stdio.h>
#include <stdlib.h>
#include <string.h> //include was missing

#define CAPACITY 17

int main(void)
{
    char *buffer = malloc(CAPACITY * sizeof(char)); //to avoid possible errors you should allocate enough space to store the data
    strcpy(buffer, "Some random text");
    printf("%s\n", buffer);
    free(buffer); //after using malloc you need yo free the memory
    return 0;
}