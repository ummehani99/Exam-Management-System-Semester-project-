#include <stdio.h>
#include <stdlib.h>   // for system("cls") and system("pause")

#define MAX 50  // srf 50 students
#define SUBJECTS 5 

int rollNo[MAX];
char name[MAX][30];
int marks[MAX][SUBJECTS];
float percentage[MAX];
int totalStudents = 0;

void addStudent();
void addMarks();
char getGrade(float p); //parameter
void showAllStudents();
void showTopper();

int main() {
    int choice;

    do {
        system("cls");
        printf("--- Exam Result Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Add Marks\n");
        printf("3. Show All Students\n");
        printf("4. Show Topper\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            addStudent();
        else if (choice == 2)
            addMarks();
        else if (choice == 3)
            showAllStudents();
        else if (choice == 4)
            showTopper();

        system("pause");

    } while (choice != 5);

    return 0;
}

void addStudent() {
    system("cls");

    if (totalStudents >= MAX) {
        printf("Student limit reached!\n");
        return;
    }

    printf("Enter Roll No: ");
    scanf("%d", &rollNo[totalStudents]);
    getchar();   // buffer clear

    printf("Enter Name: ");
    fgets(name[totalStudents], 30, stdin);


    for (int i = 0; i < SUBJECTS; i++)
        marks[totalStudents][i] = -1;

    percentage[totalStudents] = 0;
    totalStudents++;

    printf("\nStudent added successfully!\n");
}

void addMarks() {
    system("cls");

    int roll, found = 0;

    printf("Enter Roll No: ");
    scanf("%d", &roll);

    for (int i = 0; i < totalStudents; i++) {
        if (rollNo[i] == roll) {
            int total = 0;
            printf("Enter marks of 5 subjects:\n");

            for (int j = 0; j < SUBJECTS; j++) {
                scanf("%d", &marks[i][j]);
                total += marks[i][j];
            }

            percentage[i] = (total / 500.0) * 100;
            found = 1;
            break;
        }
    }
    
    if (!found)
        printf("Student not found!\n");
}

char getGrade(float p) {
    if (p >= 80) return 'A';
    else if (p >= 65) return 'B';
    else if (p >= 50) return 'C';
    else return 'F';
}

void showAllStudents() {
    system("cls");

    printf("Roll\tName\tPercentage\tGrade\n");

    for (int i = 0; i < totalStudents; i++) {
        printf("%d\t%s\t%.2f\t\t%c\n",
               rollNo[i], name[i],
               percentage[i], getGrade(percentage[i]));
    }
}

void showTopper() {
    system("cls");

    int top = 0;

    for (int i = 1; i < totalStudents; i++) {
        if (percentage[i] > percentage[top])
            top = i;
    }

    printf("Topper: %s (%.2f%%)\n",
           name[top], percentage[top]);
}
