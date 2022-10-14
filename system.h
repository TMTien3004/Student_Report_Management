#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 10

int count_arr[max] = {0};

struct student
{
    int roll_no;
    char name[20];
    char gender[2];
    char class_name[5];
    char grade;
    int math_mark, physics_mark, chem_mark, bio_mark, lit_mark, eng_mark, his_mark, geo_mark, cs_mark, civ_mark;
    int avg_mark;
};

struct student studentrecord[max];

void MainMenu()
{
    system("clear");
    printf("===================================================|\n");
    printf("|     STUDENT REPORT MANAGEMENT SYSTEM VER 1.0     |\n");
    printf("====================================================\n");
    printf("|  1. Add New Student                              |\n");
    printf("|  2. Modify Student Profile                       |\n");
    printf("|  3. Add Student Marks                            |\n");
    printf("|  4. Modify Student Marks                         |\n");
    printf("|  5. Delete Student Profile                       |\n");
    printf("|  6. Search Student Profile                       |\n");
    printf("|  7. Show list of all students                    |\n");
    printf("|  8. Save file                                    |\n");
    printf("====================================================\n\n");
}

// Add info of a new student
void AddStudent()
{
    int choice;
    char temp[20];
    int pos;

    system("clear");
    for (int i = 0; i < max; i++)
    {
        if (count_arr[i])
        {
            pos = i;
            break;
        }
    }

    studentrecord[pos].roll_no = pos + 1;
    count_arr[pos] = 1;

    printf("\nEnter student full name: ");
    fflush(stdin);
    gets(temp);
    strcpy(studentrecord[pos].name, temp);

    printf("\nEnter gender (M/F): ");
    fflush(stdin);
    gets(temp);
    strcpy(studentrecord[pos].gender, temp);

    printf("\nEnter student class: ");
    fflush(stdin);
    gets(temp);
    strcpy(studentrecord[pos].class_name, temp);

    printf("%s roll number is: %d", studentrecord[pos].name, studentrecord[pos].roll_no);
    printf("\n\nStudent created successfully!\n\n");
}

// Modify a student's info
void ModifyStudent(int pos)
{
    int choice;
    char temp[20];

    system("clear");
    if (studentrecord[pos].roll_no == pos + 1)
    {
        printf("Which information do you want to edit?\n1. Edit all\n2. Name\n3. Gender\n4. Class\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter student full name: ");
            fflush(stdin);
            gets(temp);
            strcpy(studentrecord[pos].name, temp);

            printf("Enter gender (M/F): ");
            fflush(stdin);
            gets(temp);
            strcpy(studentrecord[pos].gender, temp);

            printf("Enter student class: ");
            fflush(stdin);
            gets(temp);
            strcpy(studentrecord[pos].class_name, temp);
            break;

        case 2:
            printf("Enter student full name: ");
            fflush(stdin);
            gets(temp);
            strcpy(studentrecord[pos].name, temp);

        case 3:
            printf("Enter gender (M/F): ");
            fflush(stdin);
            gets(temp);
            strcpy(studentrecord[pos].gender, temp);

        case 4:
            printf("Enter student class: ");
            fflush(stdin);
            gets(temp);
            strcpy(studentrecord[pos].class_name, temp);

        default:
            printf("Invalid choice!\n");
            break;
        }
    }
    else
        printf("Student is not available in the list!");
}

// Delete a student's info
void DeleteStudent(int pos)
{
    int choice;
    if (studentrecord[pos].roll_no == pos + 1)
    {
        printf("Are you sure? (Yes: 1 || No: 0): ");
        scanf("%d", &choice);
        if (choice == 1)
            count_arr[pos] = 0;
    }
    else
        printf("Account does not exist!\n");
}

// Evaluate a student's results: A, B, C, D, F
void Evaluate()
{
    // Calculate average mark
    int pos;
    studentrecord[pos].avg_mark = (studentrecord[pos].math_mark + studentrecord[pos].lit_mark + studentrecord[pos].eng_mark + studentrecord[pos].physics_mark + studentrecord[pos].chem_mark + studentrecord[pos].bio_mark + studentrecord[pos].his_mark + studentrecord[pos].geo_mark + studentrecord[pos].cs_mark + studentrecord[pos].civ_mark) / 10;
    printf("\nAverage mark: %d", studentrecord[pos].avg_mark);

    if (studentrecord[pos].avg_mark >= 90)
        studentrecord[pos].grade = 'A';

    else if (studentrecord[pos].avg_mark >= 80)
        studentrecord[pos].grade = 'B';

    else if (studentrecord[pos].avg_mark >= 70)
        studentrecord[pos].grade = 'C';

    else if (studentrecord[pos].avg_mark >= 60)
        studentrecord[pos].grade = 'D';

    else
        studentrecord[pos].grade = 'F';

    printf("\nRank: %c", studentrecord[pos].grade);
}

// Search a student's full info
// Uncompleted: Rank (Sorting system)
void SearchStudent(int pos)
{
    int choice;
    if (studentrecord[pos].roll_no == pos + 1)
    {
        printf("Roll number of student: %d\n", studentrecord[pos].roll_no);
        printf("Name of student: %s\n", studentrecord[pos].name);
        printf("Gender: %s\n", studentrecord[pos].gender);
        printf("Class: %s\n", studentrecord[pos].class_name);

        printf("\nMarks in Math: %d", studentrecord[pos].math_mark);
        printf("\nMarks in Literature: %d", studentrecord[pos].lit_mark);
        printf("\nMarks in Language (English): %d", studentrecord[pos].eng_mark);
        printf("\nMarks in Physics: %d", studentrecord[pos].physics_mark);
        printf("\nMarks in Chemistry: %d", studentrecord[pos].chem_mark);
        printf("\nMarks in Biology: %d", studentrecord[pos].bio_mark);
        printf("\nMarks in History: %d", studentrecord[pos].his_mark);
        printf("\nMarks in Geography: %d", studentrecord[pos].geo_mark);
        printf("\nMarks in Computer Science: %d", studentrecord[pos].cs_mark);
        printf("\nMarks in Civic Education: %d", studentrecord[pos].civ_mark);

        Evaluate();
    }
    else
        printf("Student does not exist!\n");
}

// Input student's results in profile
void AddMarks(int pos)
{
    int choice;
    if (studentrecord[pos].roll_no == pos + 1)
    {
        printf("\nMarks in Math: ");
        scanf("%d", &studentrecord[pos].math_mark);

        printf("\nMarks in Literature: ");
        scanf("%d", &studentrecord[pos].lit_mark);

        printf("\nMarks in Language (English): ");
        scanf("%d", &studentrecord[pos].eng_mark);

        printf("\nMarks in Physics: ");
        scanf("%d", &studentrecord[pos].physics_mark);

        printf("\nMarks in Chemistry: ");
        scanf("%d", &studentrecord[pos].chem_mark);

        printf("\nMarks in Biology: ");
        scanf("%d", &studentrecord[pos].bio_mark);

        printf("\nMarks in History: ");
        scanf("%d", &studentrecord[pos].his_mark);

        printf("\nMarks in Geography: ");
        scanf("%d", &studentrecord[pos].geo_mark);

        printf("\nMarks in Computer Science: ");
        scanf("%d", &studentrecord[pos].cs_mark);

        printf("\nMarks in Civic Education: ");
        scanf("%d", &studentrecord[pos].civ_mark);

        printf("\n\nAll marks are successfully saved!\n\n");
    }
    else
        printf("Student does not exist!\n");
}

// Modify a student's result
void ModifyMarks(int pos)
{
    int choice;
    char temp[20];

    system("clear");
    if (studentrecord[pos].roll_no == pos + 1)
    {
        printf("Which grade do you want to modify?\n1. Modify all\n2. Math\n3. Literature\n4. Language (English)\n5. Physics\n6. Chemistry\n7. Biology\n8. History\n9. Geography\n10. Computer Science\n11. Civic Education\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nMarks in Math: ");
            scanf("%d", &studentrecord[pos].math_mark);

            printf("\nMarks in Literature: ");
            scanf("%d", &studentrecord[pos].lit_mark);

            printf("\nMarks in Language (English): ");
            scanf("%d", &studentrecord[pos].eng_mark);

            printf("\nMarks in Physics: ");
            scanf("%d", &studentrecord[pos].physics_mark);

            printf("\nMarks in Chemistry: ");
            scanf("%d", &studentrecord[pos].chem_mark);

            printf("\nMarks in Biology: ");
            scanf("%d", &studentrecord[pos].bio_mark);

            printf("\nMarks in History: ");
            scanf("%d", &studentrecord[pos].his_mark);

            printf("\nMarks in Geography: ");
            scanf("%d", &studentrecord[pos].geo_mark);

            printf("\nMarks in Computer Science: ");
            scanf("%d", &studentrecord[pos].cs_mark);

            printf("\nMarks in Civic Education: ");
            scanf("%d", &studentrecord[pos].civ_mark);

        case 2:
            printf("\nMarks in Math: ");
            scanf("%d", &studentrecord[pos].math_mark);

        case 3:
            printf("\nMarks in Literature: ");
            scanf("%d", &studentrecord[pos].lit_mark);

        case 4:
            printf("\nMarks in Language (English): ");
            scanf("%d", &studentrecord[pos].eng_mark);

        case 5:
            printf("\nMarks in Physics: ");
            scanf("%d", &studentrecord[pos].physics_mark);

        case 6:
            printf("\nMarks in Chemistry: ");
            scanf("%d", &studentrecord[pos].chem_mark);

        case 7:
            printf("\nMarks in Biology: ");
            scanf("%d", &studentrecord[pos].bio_mark);

        case 8:
            printf("\nMarks in History: ");
            scanf("%d", &studentrecord[pos].his_mark);

        case 9:
            printf("\nMarks in Geography: ");
            scanf("%d", &studentrecord[pos].geo_mark);

        case 10:
            printf("\nMarks in Computer Science: ");
            scanf("%d", &studentrecord[pos].cs_mark);

        case 11:
            printf("\nMarks in Civic Education: ");
            scanf("%d", &studentrecord[pos].civ_mark);

        default:
            printf("Invalid choice!\n");
            break;
        }
    }
    else
        printf("Student is not available in the list!");
}

// Show info of 1 student
void ShowInfoStudent(int pos)
{
    printf("Roll number of student: %d\n", studentrecord[pos].roll_no);
    printf("Name of student: %s\n", studentrecord[pos].name);
    printf("Gender: %s\n", studentrecord[pos].gender);
    printf("Class: %s\n", studentrecord[pos].class_name);

    printf("\nMarks in Math: %d", studentrecord[pos].math_mark);
    printf("\nMarks in Literature: %d", studentrecord[pos].lit_mark);
    printf("\nMarks in Language (English): %d", studentrecord[pos].eng_mark);
    printf("\nMarks in Physics: %d", studentrecord[pos].physics_mark);
    printf("\nMarks in Chemistry: %d", studentrecord[pos].chem_mark);
    printf("\nMarks in Biology: %d", studentrecord[pos].bio_mark);
    printf("\nMarks in History: %d", studentrecord[pos].his_mark);
    printf("\nMarks in Geography: %d", studentrecord[pos].geo_mark);
    printf("\nMarks in Computer Science: %d", studentrecord[pos].cs_mark);
    printf("\nMarks in Civic Education: %d", studentrecord[pos].civ_mark);

    Evaluate();
}

// Show info of all student
void ShowListStudent()
{
    {
        system("clear");
        printf("==============================================\n");
        printf("|                ACCOUNT LIST                |\n");
        printf("==============================================\n");
        for (int i = 0; i < max; i++)
        {
            if (count_arr[i] == 1)
                ShowInfoStudent(i);
        }
    }
}
