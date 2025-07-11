/*
This is program is about Structs in C
by Funnelwebtaipan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for personal information
typedef struct
{
    char name[220];
    int age;
    char address[100];
} person;

// printing the information (not used in this version, but kept for reference)
void print_person(person per)
{
    printf("Name is: %s\n", per.name);
    printf("Age is: %d\n", per.age);
    printf("Address is: %99s\n\n", per.address);
}

// Fill the information array with formatted person info strings
void profile(char **information)
{
    person names[] =
    {
        {"Allan", 40, "Unknown"},
        {"Vai", 32, "Unknown"},
        {"Luna", 3, "Unknown"},
        {"Judah", 0, "Unknown"}
    };

    int length = sizeof(names) / sizeof(names[0]);

    for (int i = 0; i < length; i++)
    {
        snprintf(information[i], 256,
                 "Name is: %s\nAge is: %d\nAddress is: %s\n\n",
                 names[i].name,
                 names[i].age,
                 names[i].address);
    }
}

// Main Program
int main()
{
    int count = 4; // number of persons

    // Allocate heap for pointers to strings
    char **information = (char **) malloc(count * sizeof(char *));
    if (information == NULL)
    {
        printf("\nFailed to allocate memory on the heap\n");
        return 1;
    }

    // Allocate heap for each string
    for (int i = 0; i < count; i++)
    {
        information[i] = (char *) malloc(256 * sizeof(char));
        if (information[i] == NULL)
        {
            printf("\nFailed to allocate memory for information[%d]\n", i);
            // Free previously allocated memory before returning
            for (int j = 0; j < i; j++)
                free(information[j]);
            free(information);
            return 1;
        }
    }

    // Fill the information array with formatted strings
    profile(information);

    // Print the stored information
    printf("\nThe list of names are:\n\n");
    for (int i = 0; i < count; i++)
    {
        printf("%s", information[i]);
    }

    // Free the allocated memory
    for (int i = 0; i < count; i++)
    {
        free(information[i]);
    }
    free(information);

    return 0;
}
