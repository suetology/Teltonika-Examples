#include <stdio.h>
//#include <stdlib.h> //include that is not used

int main(void)
{
    char user_input[10];        //it is better to use static array here
    printf("Enter your text: ");
    fscanf(stdin, "%10[^\n]", user_input);  //to make input safe we need to specify exact number of characters read 
    printf("\nYour line -> %s\n", user_input);
    return 0;
}