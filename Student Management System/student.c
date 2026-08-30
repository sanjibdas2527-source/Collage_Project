#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int id;
    char name[50];
    float fees;
    int paid;
    char course[10];
    char result[15];

    struct Student *next;
};


void addStudent();
void displayStudent();
void searchStudent();
void deleteStudent();
void payFees();
void allocateCourse();
void enterResult();
void saveData();
void loadData();
void countStudent();

int checkID(int id);

struct Student *head = NULL;



int login()
{
    char username[20];
    char password[20];

    printf("\n==============LOGIN SYSTEM===============\n");
 
    printf("Enter User ID: ");
    scanf("%s", username);

    printf("Enter Password: ");
    scanf("%s", password);

    if (strcmp(username, "admin") == 0 &&
        strcmp(password, "1234") == 0)
    {
        printf("\nLogin Successful!\n");
        return 1;
    }
    else
    {
        printf("\nWrong User ID or Password!\n");
        return 0;
    }
}


int checkID(int id)
{
    struct Student *temp;

    temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            return 1;   
        }

        temp = temp->next;
    }

    return 0;  
}

void addStudent()
{
    struct Student *newStudent;
    struct Student *temp;

    newStudent = (struct Student *)malloc(sizeof(struct Student));

    printf("\n===============ADD STUDENT===============\n");
    

    printf("Enter Student ID: ");
    scanf("%d", &newStudent->id);

   

    if (checkID(newStudent->id) == 1)
    {
        printf("\nThis Student ID already exists!\n");
        printf("Please enter a different ID.\n");

        free(newStudent);

        return;
    }

    printf("Enter Student Name: ");
    scanf(" %[^\n]", newStudent->name);

    printf("Enter Fees: ");
    scanf("%f", &newStudent->fees);

    newStudent->paid = 0;

    strcpy(newStudent->course, "None");

    strcpy(newStudent->result, "Pending");

    newStudent->next = NULL;

    if (head == NULL)
    {
        head = newStudent;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newStudent;
    }

    saveData();

    printf("\nStudent Added Successfully!\n");
}




void displayStudent()
{
    struct Student *temp;

    if (head == NULL)
    {
        printf("\nNo Student Record Found!\n");
        return;
    }

    temp = head;

    printf("\n=============STUDENT DETAILS==============\n");
    

    while (temp != NULL)
    {
        printf("\nStudent ID : %d", temp->id);
        printf("\nName       : %s", temp->name);
        printf("\nFees       : %.2f", temp->fees);

        if (temp->paid == 1)
            printf("\nFee Status : Paid");
        else
            printf("\nFee Status : Not Paid");

        printf("\nCourse     : %s", temp->course);
        printf("\nResult     : %s", temp->result);

        printf("\n------------------------------------\n");

        temp = temp->next;
    }
}


void searchStudent()
{
    int id;
    int found = 0;

    struct Student *temp;

    printf("\nEnter Student ID: ");
    scanf("%d", &id);

    temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            printf("\nStudent Found!\n");

            printf("ID       : %d\n", temp->id);
            printf("Name     : %s\n", temp->name);
            printf("Fees     : %.2f\n", temp->fees);
            printf("Course   : %s\n", temp->course);
            printf("Result   : %s\n", temp->result);

            found = 1;
            break;
        }

        temp = temp->next;
    }

    if (found == 0)
    {
        printf("\nStudent Not Found!\n");
    }
}


/* Pay Fees */

void payFees()
{
    int id;

    struct Student *temp;

    printf("\nEnter Student ID: ");
    scanf("%d", &id);

    temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            if (temp->paid == 1)
            {
                printf("\nFees Already Paid!\n");
            }
            else
            {
                temp->paid = 1;

                saveData();

                printf("\nFees Paid Successfully!\n");
            }

            return;
        }

        temp = temp->next;
    }

    printf("\nStudent Not Found!\n");
}


void allocateCourse()
{
    int id;
    int choice;

    struct Student *temp;

    printf("\nEnter Student ID: ");
    scanf("%d", &id);

    temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            if (temp->paid == 0)
            {
                printf("\nPlease Pay Fees First!\n");
                return;
            }

            printf("\n==============COURSE LIST=============\n");
           
            printf("1. DS\n");
            printf("2. AI\n");
            printf("3. ML\n");
            printf("4. Web\n");

            printf("Enter Choice: ");
            scanf("%d", &choice);

            if (choice == 1)
            {
                strcpy(temp->course, "DS");
            }
            else if (choice == 2)
            {
                strcpy(temp->course, "AI");
            }
            else if (choice == 3)
            {
                strcpy(temp->course, "ML");
            }
            else if (choice == 4)
            {
                strcpy(temp->course, "Web");
            }
            else
            {
                printf("\nWrong Choice!\n");
                return;
            }

            saveData();

            printf("\nCourse Allocated Successfully!\n");

            return;
        }

        temp = temp->next;
    }

    printf("\nStudent Not Found!\n");
}


void enterResult()
{
    int id;
    int choice;

    struct Student *temp;

    printf("\nEnter Student ID: ");
    scanf("%d", &id);

    temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            if (strcmp(temp->course, "None") == 0)
            {
                printf("\nFirst Allocate a Course!\n");
                return;
            }

            printf("\n==============RESULT===============\n");
            

            printf("1. Excellent\n");
            printf("2. Good\n");
            printf("3. Fail\n");

            printf("Enter Choice: ");
            scanf("%d", &choice);

            if (choice == 1)
            {
                strcpy(temp->result, "Excellent");
            }
            else if (choice == 2)
            {
                strcpy(temp->result, "Good");
            }
            else if (choice == 3)
            {
                strcpy(temp->result, "Fail");
            }
            else
            {
                printf("\nWrong Choice!\n");
                return;
            }

            saveData();

            printf("\nResult Added Successfully!\n");

            return;
        }

        temp = temp->next;
    }

    printf("\nStudent Not Found!\n");
}


void deleteStudent()
{
    int id;

    struct Student *temp;
    struct Student *prev;

    printf("\nEnter Student ID: ");
    scanf("%d", &id);

    temp = head;
    prev = NULL;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            if (prev == NULL)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }

            free(temp);

            saveData();

            printf("\nStudent Deleted Successfully!\n");

            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("\nStudent Not Found!\n");
}


void countStudent()
{
    int count = 0;

    struct Student *temp;

    temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("\nTotal Students = %d\n", count);
}


void saveData()
{
    FILE *file;

    struct Student *temp;

    file = fopen("students.txt", "w");

    if (file == NULL)
    {
        printf("\nFile Error!\n");
        return;
    }

    temp = head;

    while (temp != NULL)
    {
        fprintf(file, "%d\n", temp->id);
        fprintf(file, "%s\n", temp->name);
        fprintf(file, "%.2f\n", temp->fees);
        fprintf(file, "%d\n", temp->paid);
        fprintf(file, "%s\n", temp->course);
        fprintf(file, "%s\n", temp->result);

        temp = temp->next;
    }

    fclose(file);
}

void loadData()
{
    FILE *file;

    struct Student *newStudent;
    struct Student *temp;

    file = fopen("students.txt", "r");

    if (file == NULL)
    {
        return;
    }

    while (1)
    {
        newStudent = (struct Student *)malloc(sizeof(struct Student));

        if (fscanf(file, "%d\n", &newStudent->id) != 1)
        {
            free(newStudent);
            break;
        }

        fgets(newStudent->name, 50, file);
        newStudent->name[strcspn(newStudent->name, "\n")] = '\0';

        fscanf(file, "%f\n", &newStudent->fees);
        fscanf(file, "%d\n", &newStudent->paid);

        fgets(newStudent->course, 10, file);
        newStudent->course[strcspn(newStudent->course, "\n")] = '\0';

        fgets(newStudent->result, 15, file);
        newStudent->result[strcspn(newStudent->result, "\n")] = '\0';

        newStudent->next = NULL;

        if (head == NULL)
        {
            head = newStudent;
        }
        else
        {
            temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newStudent;
        }
    }

    fclose(file);
}


int main()
{
    int choice;

    printf("\n=====STUDENT COURSE AND RESULT MANAGEMENT SYSTEM=====\n");
    
    if (login() == 0)
    {
        printf("\nProgram Closed!\n");
        return 0;
    }


    loadData();


    while (1)
    {
        printf("\n===========MAIN MENU==============\n");
        
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Pay Fees\n");
        printf("5. Allocate Course\n");
        printf("6. Enter Result\n");
        printf("7. Delete Student\n");
        printf("8. Count Students\n");
        printf("9. Save Data\n");
        printf("10. Exit\n");

        printf("====================================\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            addStudent();
        }
        else if (choice == 2)
        {
            displayStudent();
        }
        else if (choice == 3)
        {
            searchStudent();
        }
        else if (choice == 4)
        {
            payFees();
        }
        else if (choice == 5)
        {
            allocateCourse();
        }
        else if (choice == 6)
        {
            enterResult();
        }
        else if (choice == 7)
        {
            deleteStudent();
        }
        else if (choice == 8)
        {
            countStudent();
        }
        else if (choice == 9)
        {
            saveData();
            printf("\nData Saved Successfully!\n");
        }
        else if (choice == 10)
        {
            saveData();

            printf("\nData Saved.\n");
            printf("Thank You!\n");

            break;
        }
        else
        {
            printf("\nWrong Choice! Try Again.\n");
        }
    }

    return 0;
}
