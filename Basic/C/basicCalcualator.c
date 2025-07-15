// Basic calculator program

#include <stdio.h>

// Assigning calculator functions

float additionf(int x, int y)
{
    return (float) x + y;
}

float subtractionf(int x, int y)
{
    return (float) x - y;
}

float multiplicationf(int x, int y)
{
    return (float) x * y;
}

float divisionf(int x, int y)
{
    return (float) x / y;
}

float pi_radius (int x)
{
    const float pi_r = 3.142;
    return (float) pi_r * (x*x);
}


// main function
int main ()
{
    int choice, x, y;
    printf("\nThis is basic calculator program\n");
    printf("\n1. Addition\n");
    printf("\n2. Subtraction\n");
    printf("\n3. Multiplication\n");
    printf("\n4. Division\n");
    printf("\n5. Pi Radius\n");
    printf("\n8. Exit\n");
    printf("\nEnter in the calculator operation:\n");

    scanf("%d", &choice);


    // Calculator functions
    switch (choice)
    {
        case 1:
            printf("\nYou have selected Addition\n");
            printf("\nEnter two numbers\n");
            scanf("%d%d", &x, &y);
            printf("\nThe sum of the values are: %f\n", additionf(x,y));
            break;
        case 2:
            printf("\nYou have selected Subtraction\n");
            printf("\nEnter two numbers:\n");
            scanf("\n%d%d", &x, &y);
            printf("\nThe sum of the two values are: %f\n", subtractionf(x,y));
            break;
        case 3:
            printf("\nYou have selected Multiplication\n");
            printf("\nEnter two numbers:\n");
            scanf("\n%d%d", &x, &y);
            printf("\nThe sum of the two values are: %f\n", multiplicationf(x,y));
            break;
        case 4:
            printf("\nYou have selected Division\n");
            printf("\nEnter two values:\n");
            scanf("\n%d%d", &x, &y);
            if (y == 0)
            {
                printf("\nCannot divide by zero\n");
                break;
            }
            printf("\nThe sum of the two values are: %f\n", divisionf(x,y));
            break;
        case 5:
            printf("\nYou have selected Pi Radius\n");
            printf("\nEnter in the radius value:\n");
            scanf("\n%d", &x);
            printf("\nThe radius is: %f\n", pi_radius(x));
            break;
        case 8:
            printf("\nYou have selected to exit the program\n");
            break;
        default:
            printf("\nInvalid choice\n");
            break;
    }
    printf("\nThank you for playing\n");
    return 0;

}