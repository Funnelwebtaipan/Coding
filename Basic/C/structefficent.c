/*
This is a more efficient of my struct example.

This program the only information is only stored once in memory.

Where as my other struct example stored the information twice.

by Funnelwebtaipan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for employment information
typedef struct
{
    char name[50];
    int age;
    char role[50];
} employment_info;

// Function to fill the employment info and assign pointers
void employment_details(employment_info **information)
{
    // Static array of data
    const char *names[] = {"John", "Jane", "Henry", "Penelope"};
    int ages[] = {40, 32, 31, 22};
    const char *roles[] = {"Manager", "Analyst", "Advisor", "Reception"};

    int count = 4;

    for (int i = 0; i < count; i++)
    {
        // Allocate space for each struct on the heap
        information[i] = (employment_info *) malloc(sizeof(employment_info));
        if (information[i] == NULL)
        {
            printf("Memory allocation failed for information[%d]\n", i);
            // Free previously allocated memory
            for (int j = 0; j < i; j++)
                free(information[j]);
            exit(1);
        }

        // Fill struct fields
        strncpy(information[i]->name, names[i], sizeof(information[i]->name) - 1);
        information[i]->age = ages[i];
        strncpy(information[i]->role, roles[i], sizeof(information[i]->role) - 1);
    }
}

// Function to print all employment information
void print_employment(employment_info **information, int count)
{
    printf("\nEmployment Records:\n\n");
    for (int i = 0; i < count; i++)
    {
        printf("Name: %s\n", information[i]->name);
        printf("Age: %d\n", information[i]->age);
        printf("Role: %s\n\n", information[i]->role);
    }
}

int main()
{
    int count = 4;

    // Allocate memory for array of struct pointers
    employment_info **information = (employment_info **) malloc(count * sizeof(employment_info *));
    if (information == NULL)
    {
        printf("Failed to allocate memory for information array\n");
        return 1;
    }

    // Populate data
    employment_details(information);

    // Print information
    print_employment(information, count);

    // Free allocated memory
    for (int i = 0; i < count; i++)
    {
        free(information[i]);
    }
    free(information);

    return 0;
}
