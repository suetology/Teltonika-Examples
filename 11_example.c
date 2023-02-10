#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMETER ","
#define CAPACITY 30

struct Person 
{
    char name[CAPACITY];
    char surname[CAPACITY];
    char number[CAPACITY];
    struct Person *next;
};

struct Person* create_node(char *name, char *surname, char *number);
struct Person* create_address_node(char *address_line);
void add_to_list(struct Person **list, struct Person *node);
void print_list(struct Person *list);
void delete_list(struct Person **list);
void load_addresses(FILE *file, struct Person **list);


int main(void)
{
    char address_file_path[30] = "addresses.csv";
    struct Person *list = NULL;
    FILE *address_file = NULL;

    address_file = fopen(address_file_path, "r");

    if(address_file == NULL) 
    {
        printf("Unable to open file\n");
        exit(1);
    }

    load_addresses(address_file, &list);
    print_list(list);
    delete_list(&list);
    fclose(address_file);
    return 0;
}

void load_addresses(FILE *file, struct Person **list)
{
    char line[128];
    while (fgets(line, sizeof(line), file)) 
    {
        if(strcmp(line, "\n") == 0) 
        {
            //exit(1); exit terminates the whole program
            continue;
        }

        line[strcspn(line, "\n")] = '\0'; //added this to remove trailing new line characters

        struct Person *person = NULL;
        person = create_address_node(line);
        if (person != NULL) 
        {
            add_to_list(list, person);
        }
    }
}

struct Person* create_address_node(char *address_line)
{
    struct Person *person = NULL;
    char *name;
    char *surname;
    char *number;

    name = strtok(address_line, DELIMETER);
    surname = strtok(NULL, DELIMETER);
    number = strtok(NULL, DELIMETER);

    person = create_node(name, surname, number);
    
    return person;
}

struct Person* create_node(char *name, char *surname, char *number)
{
    struct Person *person = NULL;
    person = (struct Person*) malloc(sizeof(struct Person));
    if (person == NULL) 
    {
        return NULL;
    }
    strcpy(person->name, name);
    strcpy(person->surname, surname);
    strcpy(person->number, number);
    person->next = NULL;
    return person;
}

void add_to_list(struct Person **list, struct Person *person)
{
    struct Person* temp = *list;
    if (temp == NULL) 
    {
        *list = person;
        return; 
    }

    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = person;
}

void print_list(struct Person *list)
{
    struct Person *temp = list;
    while (temp != NULL) 
    {
        printf("%s %s %s\n", temp->name, temp->surname, temp->number); //added new line character here for better looking output
        temp = temp->next;
    }
}

void delete_list(struct Person **list)  //with single pointer this function frees all the memory but does not set list to NULL so we need to use double pointer
{
    struct Person *to_delete = *list;
    while (*list != NULL) 
    {
        *list = (*list)->next;
        free(to_delete);
        to_delete = *list;
    }
}