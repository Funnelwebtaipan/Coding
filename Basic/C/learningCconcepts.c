/*
As a new progrmmer to C I am learning various concepts

This program is to document those concepts

My aim over time is make this program more advanced as my knowledge
increases

by Funnelwebtaipan
*/

// Import libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// The basic print statement
void basic_statement()
{
    
    printf("\nHello, World\n");
}

// Random number generator
void random_number()
{
    
    // Setting random seed
    srand((unsigned int)time(NULL));

    // Generating and printing random number
    int min = 1;
    int max = 100;
    int numberinbetween = (rand() % (max - min + 1)) + min;
    printf("\nThe random is %d\n", numberinbetween);
    
    // If statement
    if (numberinbetween < 50)
    {
        printf("\nRandom number is less than halfway of 100\n");
    }
    else
    {
        printf("\nRandom number is over halfway of 100\n");
    }
    printf("\n");
}

// Loops - Strings
void looping_strings()
{
    // Input from user
    printf("\nEnter five Japanese cars brands:\n");
    char cars [5][11] = {};
    int len = sizeof(cars) / sizeof(cars[0]);

    // Looping through customer imports of japanese cars
    for (int i = 0; i < len; i++)
    {
        printf("\nEnter car brand %d: ", i + 1);
        scanf("%10s", cars[i]);
    }

    // Printing the list of japanese cars
    printf("\nThe Japanese car brands you entered are: \n");
    for (int i = 0; i < len; i++)
    {
        printf("%s\n", cars[i]);
    }
}

// Loops - numbers
void looping_numbers()
{
    // Input from user
    printf("\nA program to enter in five numbers:\n");
    int numbers [5] = {};

    // Looping through input five numbers
    for (int i = 0; i < 5; i++)
    {
        printf("\nEnter numbers %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    // looping through printing five number
    printf("\nThe numbers you entered are:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", numbers[i]);
    }

}

// Comparison function for qsort
int compare_strings(const void *a, const void *b)
{
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;
    return strcmp(str1, str2);
}

// Strings example stored on the heap
void random_number_string_heap()
{
    // Determing the size of the heap
    printf("\nEnter in the number of random words you wish to enter between 1 and 10:\n");
    int word_count;
    scanf("%d", &word_count);
    // Validating input
    if (word_count > 10 || word_count <= 0)
    {
        printf("\nInvalid input, word count must be between 1 and 10\n");
        return;
    }

    // Allocating memory to the heap
    char **words = (char **) malloc(word_count * sizeof(char *));
    if (words == NULL)
    {
        printf("\nFailed to allocate memory\n");
        return;
    }

    // Taking input from users - random words
    printf("\nEnter in random words:\n");
    for (int i = 0; i < word_count; i++)
    {
        words[i] = (char *) malloc(100 * sizeof(char));
        if (words[i] == NULL)
        {
            printf("\nMemory allocation failed for word %d\n", i + 1);

            // Clean up previously allocated strings
            for (int j = 0; j < i; j++)
            {
                free(words[j]);
            }

            free(words); // Free the pointer array itself
            words = NULL;
            return;
        }

        printf("\nWord %d: ", i + 1);
        scanf("%99s", words[i]);
    }
    // Sort the strings alphabetically
    printf("\nList will be sorted alphabetically\n");
    qsort(words, word_count, sizeof(char *), compare_strings);
    // Printing the sorted list
    printf("\nYou have entered:\n");
    for (int j = 0; j < word_count; j++) 
    {
        printf("%s\n", words[j]);
        free(words[j]); // Free each word
    }
    free(words);
    words = NULL;
}

// Points to a memory address
void memory_pointer()
{
    // Assigining variables
    printf("\nThis programs point to a memory address\n");
    int num1;
    if (scanf("%d", &num1) != 1)
    {
        printf("\nInvalid input. Exiting\n");
        return;
    }
    int *num = &num1;
    printf("\nNum1 value is: %d\n", num1); // Displaying the value of num1
    printf("\nAddress of num1: %p\n", (void *)&num1);
    printf("\nAddress stored in number pointer %p\n", (void *)num);
}

// Confirming whether or not to continue
char ask_to_continue(void)
{
    char input;
    do {
        printf("\nWould you like to try another concept? (y/n): ");
        scanf(" %c", &input);  // Space skips leftover newline

        if (input != 'y' && input != 'Y' && input != 'n' && input != 'N') {
            printf("\nInvalid input. Please enter 'y' or 'n'.\n");
        }

    } while (input != 'y' && input != 'Y' && input != 'n' && input != 'N');

    return input;
}

// Main function
int main (void) 
{
    // Assiging variables
    int choice = 0;
    char again;

    // Interative menu
    do {
        printf("\nChoose from one of the basic concepts:\n");
        printf("\nPrograms stored on the stack:\n");
        printf("\n1. Basic printing statement\n");
        printf("\n2. Random number generator / If statement\n");
        printf("\n3. Loops - Strings\n");
        printf("\n4. Loops - Integers\n");
        printf("\n5. Memory pointer example\n");
        printf("\nPrograms stored on the heap:\n");
        printf("\n6. Storing a string of arrays on the heap\n");
        printf("\n7. Exit\n");
        printf("\nEnter your choice:\n");
        scanf("%d", &choice);

        // Decision
        switch (choice)
        {
            case 1:
                printf("\nYou have selected the basic programming printing statement\n");
                basic_statement();
                break;
            case 2:
                printf("\nYou have selected Random Number Generator\n");
                random_number();
                break;
            case 3:
                printf("\nYou have selected Loops - Strings\n");
                looping_strings();
                break;
            case 4:
                printf("\nYou have selected loops - Integers\n");
                looping_numbers();
                break;
            case 5:
                printf("\nYou have selected pointing to a memory inspector\n");
                memory_pointer();
                break;
            case 6:
                printf("\nYou have selected - Strings stored on the heap\n");
                random_number_string_heap();
                break;
            case 7:
                printf("\nYou have selected to exit\n");
                break;
            default:
                printf("\nInvalid choice. Please try again\n");
                continue;  // Skip rest and go back to top of loop
        }
        // Ask if the user wants to try another concept
        again = ask_to_continue();

    // Confirming whether to continue
    } while (again == 'y' || again == 'Y');

    // Goodbye statement
    printf("\nThanks for exploring C concepts. Goodbye!\n");
    return 0;
}
