#include <stdio.h>

void number_changer(int *var) //in order to change value of function parameter int so that it is changed in whole program we need to pass a pointer to it
{
    printf("Number changer. Before change - %d\n", *var); //to get the value of int* we need to dereference it
    *var = 123;
    printf("Number changer. After change - %d\n", *var);
}

int main(void)
{
    int var = 766;
    printf("Before change - %d\n", var);
    number_changer(&var);
    printf("After change - %d\n", var);
    return 0;
}