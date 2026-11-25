#include <stdio.h>

int calculateTotal(int marks[])
{
    int total = 0;

    for(int i = 0; i < 5; i++)
    {
        total = total + marks[i];
    }

    return total;
}

float calculateAverage(int total)
{
    return total / 5.0;
}

void calculateGrade(float average, char grade[], float *gpa)
{
    if(average >= 80)
    {
        grade[0] = 'A';
        grade[1] = '+';
        grade[2] = '\0';
        *gpa = 4.00;
    }
    else if(average >= 70)
    {
        grade[0] = 'A';
        grade[1] = '\0';
        *gpa = 3.50;
    }
    else if(average >= 60)
    {
        grade[0] = 'A';
        grade[1] = '-';
        grade[2] = '\0';
        *gpa = 3.00;
    }
    else if(average >= 50)
    {
        grade[0] = 'B';
        grade[1] = '\0';
        *gpa = 2.50;
    }
    else if(average >= 40)
    {
        grade[0] = 'C';
        grade[1] = '\0';
        *gpa = 2.00;
    }
    else
    {
        grade[0] = 'F';
        grade[1] = '\0';
        *gpa = 0.00;
    }
}

void displayResult(char name[], char id[],
                   int total, float average,
                   char grade[], float gpa,
                   int fail)
{
    printf("\n------ Student Result ------\n");

    printf("Name    : %s\n", name);
    printf("ID      : %s\n", id);
    printf("Total   : %d\n", total);
    printf("Average : %.2f\n", average);
    printf("Grade   : %s\n", grade);
    printf("GPA     : %.2f\n", gpa);

    if(fail == 1)
        printf("Result  : Fail\n");
    else
        printf("Result  : Pass\n");
}

int main()
{
    char name[100], id[30], grade[5];
    int marks[5], total, fail = 0;
    float average, gpa;

    printf("Enter student name: ");
    scanf(" %[^\n]", name);

    printf("Enter student ID: ");
    scanf("%s", id);

    for(int i = 0; i < 5; i++)
    {
        do
        {
            printf("Enter mark of subject %d: ", i + 1);
            scanf("%d", &marks[i]);

            if(marks[i] < 0 || marks[i] > 100)
            {
                printf("Invalid marks! Enter 0-100.\n");
            }

        } while(marks[i] < 0 || marks[i] > 100);

        if(marks[i] < 40)
        {
            fail = 1;
        }
    }

    total = calculateTotal(marks);

    average = calculateAverage(total);

    calculateGrade(average, grade, &gpa);

    displayResult(name, id, total, average,
                  grade, gpa, fail);

    return 0;
}
