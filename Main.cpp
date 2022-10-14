#include "system.h"

int main()
{
    int continue_var, pos;
    do
    {
        MainMenu();
        int choice;

        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            AddStudent();
            break;
        case 2:
            printf("Enter student roll number you want to modify: ");
            scanf("%d", &pos);
            ModifyStudent(pos - 1);
            break;
        case 3:
            printf("Enter student roll number to input grades: ");
            scanf("%d", &pos);
            AddMarks(pos - 1);
            break;
        case 4:
            printf("Enter student roll number to update grades: ");
            scanf("%d", &pos);
            ModifyMarks(pos - 1);
            break;
        case 5:
            printf("Enter student roll number to delete profile: ");
            scanf("%d", &pos);
            DeleteStudent(pos - 1);
            break;
        case 6:
            printf("Enter student roll number to look at: ");
            scanf("%d", &pos);
            SearchStudent(pos - 1);
            break;
        case 7:
            
            break;
     /* case 8:       // case 8 is not completed, yet....

            break; */
        default:
            printf("\nInvalid choice!\n");
            break;
        }

        printf("\nContinue? Yes: 1| No: 0: ");
        scanf("%d", &continue_var);
    } while (continue_var != 0);
    return 0;
}
