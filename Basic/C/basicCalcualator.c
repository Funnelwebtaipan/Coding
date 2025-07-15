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
    printf("This is basic calculator program\n");
    printf("Enter in the calculator operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Pi Radius\n");
    printf("8. Exit\n");
    scanf("%d", &choice);


    // Calculator functions
    switch (choice)
    {
        case 1:
            printf("You have selected Addition\n");
            printf("Enter two numbers\n");
            scanf("%d%d", &x, &y);
            printf("The sum of the values are %f\n", additionf(x,y));
            break;
        case 2:
            printf("You have selected Subtraction\n");
            printf("Enter two numbers:\n");
            scanf("%d%d", &x, &y);
            printf("The sum of the two values are:\n", subtractionf(x,y));
            break;
        case 3:
            printf("You have selected Multiplication\n");
            printf("Enter two numbers:\n");
            scanf("%d%d", &x, &y);
            printf("The sum of the two values are %f\n", multiplicationf(x,y));
            break;
        case 4:
            printf("You have selected Division\n");
            printf("Enter two values:\n");
            scanf("%d%d", &x, &y);
            if (y == 0)
            {
                printf("Cannot divide by zero\n");
                break;
            }
            printf("The sum of the two values are:%f\n", divisionf(x,y));
            break;
        case 5:
            printf("You have selected Pi Radius\n");
            printf("Enter in the radius value:\n");
            scanf("%d", &x);
            printf("The radius is %f\n", pi_radius(x));
            break;
        case 8:
            printf("You have selected to exit the program\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    return 0;

}