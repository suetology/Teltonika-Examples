#include <stdio.h>
#include <string.h>

#define CAPACITY 38

int main(void)
{
    //char buffer[20]; size of array should be big enough to store all the data
    char buffer[CAPACITY]; // also it is probably better to use const variables or defines to specify the size of arrays
    strcpy(buffer, "Copy this text to the buffer variable");
    printf("%s\n", buffer);
    return 0;
}