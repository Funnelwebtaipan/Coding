/*
Student Information Management System

website: geeksforgeeks.org

For my own eductional and learning

by Funnelwebtaipan*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variable to keep track of number of students
int i = 0;

// Structure to store the info
struct studentinfo
{
    char fname[30];
    char lname[30];
    int age;
    int roll;
    float gpa;
    int studentid [10];
    int cid[10];

} stud[55];

// Function to add the student info
void add_student()
{
    printf("Student Details\n");
    printf("----------------------------------------\n");
    printf("Enter the student's first name:\n");
    scanf("%s", stud[i].fname);
    printf("Enter the student's last name\n");
    scanf("%s", stud[i].lname);
    printf("Enter the student's age:\n");
    scanf("%d", stud[i].age);
    printf("Enter the roll number:\n");
    scanf("%d", stud[i].age);
    printf("Enter the GPA obtained:\n");
    scanf("%d", stud[i].gpa);
    printf("Enter the student id number:\n");
    scanf("%d", stud[i].studentid);
    printf("Enter the course id:\n");
    for (int j = 0; j < 5; j++)
    {
        scanf("%d", &stud[i].cid[j]);
    }
    i = i + 1;
}

// Function to find the student by role number
void find_rl()
{
    int x;
    printf("Enter the roll number of the student\n");
    scanf("%d", &x);
    for (int j = 1; j <= i; j++)
    {
        if (x == stud[i].roll)
        {
            printf("The student's details are:\n");
            printf("The first name is %s:\n", stud[i].fname);
            
        }
    }
}



