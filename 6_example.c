#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> //include was missing

#define SIZE 6

void genRandomText(int count, char *buffer)
{
    int i;
    for (i = 0; i < count; i++) 
    { //alignment of parenthesis should be the same everywhere
        char num = (rand() % (90 - 65 + 1)) + 65; //since we know that the value of num will not exceed 255 it is probably better to make this variable's type char
        //char symbol[1];
        //sprintf(symbol,"%c", num);
        //strcat(buffer, symbol);
        //it is probably more optimized to directly assign the values to the array elements
        buffer[i] = num;
    }
    buffer[count] = '\0';
}

int main()
{
    char *buffer = malloc((SIZE + 1) * sizeof(char));
    int i = 1;
    srand(time(0));
  
    while(i < 7) 
    {
        //buffer = malloc(i * sizeof(char) + 1); using malloc several times without free cause memory leaks, need to use realloc
        //also in this situation it is better to just allocate memory once before loop
        genRandomText(i, buffer);
        printf("Buffer - %s\n", buffer);
        i++;
    }
    free(buffer);
    return 0;
}