/*
As a new progrmmer to C I am learning various concepts

This program is to document those concepts

My aim over time is make this program more advanced as my knowledge
increases

by Funnelwebtaipan
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void basic_statement()
{
    // The basic
    printf("Hello, World\n");
}

void random_number()
{
    // If statement combined with random number generator
    // Setting random seed
    srand((unsigned int)time(NULL));

    // Generating and printing random number
    int min = 1;
    int max = 100;
    int numberinbetween = (rand() % (max - min + 1)) + min;
    printf("The random is %d\n", numberinbetween);
    if (numberinbetween < 50)
    {
        printf("Random number is less than halfway\n");
    }
    else
    {
        printf("Random number is over halfway\n");
    }
    printf("\n");
}

void looping_strings()
{
    printf("Enter five Japanese cars brands:\n");
    char cars [5][11] = {};
    int len = sizeof(cars) / sizeof(cars[0]);

    // Looping through customer imports of japanese cars
    for (int i = 0; i < len; i++)
    {
        printf("Enter car brand %d", i + 1);
        scanf("%10s", cars[i]);
    }

    // Printing the list of japanese cars
    printf("\nThe Japanese car brands you entered are: \n");
    for (int i = 0; i < len; i++)
    {
        printf("%s\n", cars[i]);
    }
}

void loopings_numbers()
{
    printf("A program to enter in five numbers:\n");
    int numbers [5] = {};

    // Looping through input five numbers
    for (int i = 0; i < 5; i++)
    {
        printf("Enter numbers: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    // looping through printing five number
    printf("The numbers you entered are:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", numbers[i]);
    }

}

int main (void) 
{
    int choice = 0;
    char again;

    do {
        printf("\nChoose from one of the basic concepts:\n");
        printf("1. Basic Statement\n");
        printf("2. Random number generator / If statement\n");
        printf("3. Loops - Strings\n");
        printf("4. loops - intergers\n");
        printf("5. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("You have selected Basic Statement\n");
                basic_statement();
                break;
            case 2:
                printf("You have selected Random Number Generator\n");
                random_number();
                break;
            case 3:
                printf("You have selected Loops - Strings\n");
                looping_strings();
                break;
            case 4:
                printf("You have selected loops - Integers\n");
                loopings_numbers();
                break;
            case 5:
                printf("You have selected to exit\n");
                break;
            default:
                printf("Invalid choice. Please select 1, 2, or 3.\n");
                continue;  // Skip rest and go back to top of loop
        }

        printf("\nWould you like to try another concept? (y/n): ");
        scanf(" %c", &again);  // Notice the space before %c to consume leftover newline
    } while (again == 'y' || again == 'Y');

    printf("Thanks for exploring C concepts. Goodbye!\n");
    return 0;   
}
