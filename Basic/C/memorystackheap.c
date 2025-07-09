/*
Program designed to understand:
- For loops
- Memory allocation
- Pointers to memory
- The difference between memory stored on the stack and on the heap

by Funnelwebtaipan*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
    // Memory stored on the stack and pointing to that memory
    // int example
    int num1 = 5;
    int *num = &num1;
    printf("Num1 value is; %d\n", num1); // Displaying the value of num1
    printf("Address num1 is (via Num1): %p\n", (void *)&num1);
    printf("Address stored in number pointer %p\n", (void *)num); // Pointing to the memory address

    printf("\n");

    // Memory stored on the stack string of arrays example
    char word_list [5][20] = {
        "Hacking", 
        "Malware", 
        "SIGINT", 
        "Cryptography", 
        "Coding"};
    int len = sizeof(word_list) / sizeof(word_list[0]); // Size of the array
    printf("List of words stored on the stack:\n");
    for (int i = 0; i < len; i++)
    {
        printf("%s\n", word_list[i]);
    }

    printf("\n");

    // Memory stored on the heap string of arrays
    char **words = (char **) malloc(5 * sizeof(char *)); // Allocating memory onto the heap
    if (words == NULL)
    {
        printf("Failed to allocate memory\n");
        return 1;
    }
    words[0] = strdup("I love Hacking");
    words[1] = strdup("I love Malware!!!");
    words[2] = strdup("I love SIGINT");
    words[3] = strdup("I love Cryptography");
    words[4] = strdup("I Love Coding");
    printf("List of words stored on the heap:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", words[i]);
        free(words[i]); // Freeing each string individually
    }
    free(words); // Freeing the memory off the heap
    words = NULL; // Safe way to free the memory off the heap
    return 0;

}