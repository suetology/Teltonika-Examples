#include <stdio.h>

int main(void)
{
    char copy_from[30] = "original_file.txt";
    char copy_to[30] = "copied_file.txt";

    FILE *original = NULL;
    FILE *copy = NULL;

    original = fopen(copy_from, "r");
    copy = fopen(copy_to, "w");

    char line[500];

    while (fgets(line, sizeof(line), original)) 
    {
        //copy = fopen(copy_to, "a+"); it is not necessary to open file in append mode every loop iteration as you can open it once in write mode
        fprintf(copy, "%s", line);
        //fclose(copy);
    }

    fclose(copy);
    fclose(original);
    return 0;
}