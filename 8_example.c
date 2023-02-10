#include <stdio.h>

void number_printer(int *var) 
{
    printf("Number is - %d\n", *var);//to get the value of int* we need to dereference it
}

int main(void)
{
    int var = 345;
    number_printer(&var);
    return 0;
}