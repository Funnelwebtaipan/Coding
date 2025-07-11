#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void random_number_string_heap()
{
    // Determing the size of the heap
    printf("Enter in the number of random words you wish to enter between 1 and 10:\n");
    int word_count;
    scanf("%d", &word_count);
    // Validating input
    if (word_count > 10 || word_count <= 0)
    {
        printf("Invalid input, word count must be between 1 and 10\n");
        return;
    }

    // Allocating memory to the heap
    char **words = (char **) malloc(word_count * sizeof(char *));
    if (words == NULL)
    {
        printf("Failed to allocate memory\n");
        return;
    }

    // Taking input from users - random words
    printf("Enter in random words:\n");
    for (int i = 0; i < word_count; i++)
    {
        words[i] = (char *) malloc(100 * sizeof(char));
        if (words[i] == NULL)
        {
            printf("Memory allocation failed for word %d\n", i + 1);
            return 0;
        }
        prinf("Word %d:", i + 1);
        scanf("%99s", &words[i]);
    }

    // Printing the output of words
    prinf("You have entered:\n");
    for (int j = 0; j < word_count; j++)
    {
        printf("%s\n", words[j]);
        free(words[j]);
    }

    // Free heap memory
    free(words);
    words = NULL;
}void random_number_string_heap()
{
    // Determing the size of the heap
    printf("Enter in the number of random words you wish to enter between 1 and 10:\n");
    int word_count;
    scanf("%d", &word_count);
    // Validating input
    if (word_count > 10 || word_count <= 0)
    {
        printf("Invalid input, word count must be between 1 and 10\n");
        return;
    }

    // Allocating memory to the heap
    char **words = (char **) malloc(word_count * sizeof(char *));
    if (words == NULL)
    {
        printf("Failed to allocate memory\n");
        return;
    }

    // Taking input from users - random words
    printf("Enter in random words:\n");
    for (int i = 0; i < word_count; i++)
    {
        words[i] = (char *) malloc(100 * sizeof(char));
        if (words[i] == NULL)
        {
            printf("Memory allocation failed for word %d\n", i + 1);
            return 0;
        }
        prinf("Word %d:", i + 1);
        scanf("%99s", &words[i]);
    }

    // Printing the output of words
    prinf("You have entered:\n");
    for (int j = 0; j < word_count; j++)
    {
        printf("%s\n", words[j]);
        free(words[j]);
    }

    // Free heap memory
    free(words);
    words = NULL;
}