/*
Program is to create a struct that stores memory on the heap

by Funnelwebtaipan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Creating struct
typedef struct 
{
    char name[50];
    int age;
} info;

void obtaining_info(info **information)
{
    int count;
    int max = 5;

    printf("\nThis program allows you to enter the name and age for up to five people\n");
    printf("Enter in how many names and ages you wish to enter:\n");
    scanf("%d", &count);

    // Validate count properly
    if (count < 1 || count > max)
    {
        printf("\nOnly values between 1 and 5 can be entered\n");
        return;  // Prevent continuing with invalid count
    }

    for (int i = 0; i < count; i++)
    {
        // Allocate space on the heap for each struct
        information[i] = (info *) malloc(sizeof(info));
        if (information[i] == NULL)  //  Was wrongly checking 'information' instead
        {
            printf("Failed memory allocation for information[%d]\n", i);
            // Free previously allocated memory
            for (int j = 0; j < i; j++)
            {
                free(information[j]);
            }
            exit(1);
        }

        printf("\nEnter the name for person %d: ", i + 1);
        scanf(" %49[^\n]", information[i]->name);  // Handles spaces

        printf("Enter the age for %s: ", information[i]->name);
        scanf("%d", &information[i]->age);  // You forgot the & (address of)
    }

    // Display entered data
    printf("\nEntered information:\n");
    for (int i = 0; i < count; i++)
    {
        printf(" %s |  %d\n", information[i]->name, information[i]->age);
    }

    // Bug: free loop is written incorrectly — it won't run!
    // You had: for (int i = 0; i < 0; i++) ← never runs
    for (int i = 0; i < count; i++)
    {
        free(information[i]);  // Free each allocated struct
    }
}

int main(void)
{
    info *information[5];  // Array of 5 pointers to info structs
    obtaining_info(information);  // Heap allocation happens inside
    return 0;
}
