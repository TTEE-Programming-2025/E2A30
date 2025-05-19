#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char name[50];
    int id;
    int math;
    int physics;
    int english;
    float average;
} Student;

Student students[10];
int student_count = 0; 
void menu()
{
    printf("------------[Grade System]----------\n");
    printf("| a. Enter student grades         |\n");
    printf("| b. Display student grades       |\n");
    printf("| c. Search for student grades    |\n");
    printf("| d. Grade ranking                |\n");
    printf("| e. Exit system                  |\n");
    printf("------------------------------------\n");
}

void enter_grades()
{
    int n;
    char name[100];
    char id_input[20];
    printf("Enter number of Students(5-10):");
    scanf("%d", &n);
    while (n < 5 || n > 10)
    {
        printf("Please enter a number between 5~10:");
        scanf("%d", &n);
    }
    student_count = n;

    getchar();
    for (int i = 0; i < student_count; i++)
    {
        printf("\n enter students %d name :", i + 1);
        getchar();
        fgets(students[i].name, 100, stdin); // 使用fgets是因為scanf無法讀取整行字串以及空格
        while (1)
        { // 檢查學生 ID 是否為六位數
            printf("Enter student ID (6 digits): ");
            scanf("%d", &students[i].id);
            // 檢查是否為數字且位數為 6
            if (students[i].id >= 100000 && students[i].id <= 999999)
            {
                break;
            }
            else
            {
                printf("ID must be exactly 6 digits!\n");
            }
        }

        printf("Enter Math score: ");
        scanf("%d", &students[i].math);
        if (students[i].math < 0 || students[i].math > 100)
        {
            printf("Please enter actual score:");
            scanf("%d", &students[i].math);
        }

        printf("Enter Physics score: ");
        scanf("%d", &students[i].physics);
        if (students[i].physics < 0 || students[i].physics < 100)
        {
            printf("Please enter actual score:");
            scanf("%d", &students[i].physics);
        }

        printf("Enter English score: ");
        scanf("%d", &students[i].english);
        if (students[i].english < 0 || students[i].english > 100)
        {
            printf("Please enter actual score:");
            scanf("%d", &students[i].english);
        }
    }
}
void display_grades(Student students[], int student_count)
{
    printf("\nName    ID      Math  Physics  English  Average\n");
    for (int i = 0; i < student_count; i++)
    {
        float average = (students[i].math + students[i].physics + students[i].english) / 3.0;
        printf("%s %d %d %d %d %.1f\n",
               students[i].name, students[i].id, students[i].math,
               students[i].physics, students[i].english, average);
    }
}

int main(void)
{
    int student_count = 0;
    system("chcp 65001");
    puts("==========================================================================");
    puts("                    Welcome to Your Personalized UI!                     ");
    puts("|----------------------------------------------------------------------");
    puts("                                                                       ");
    puts("|  EEEEEEEEEEE       222222222           A           3333333     0000000.  ");
    puts("|  E                        22          A A               33     0     0   ");
    puts("|  E                       22          A   A              33     0     0   ");
    puts("|  EEEEEEEEEEE            22          A     A        3333333     0     0   ");
    puts("   EEEEEEEEEEE           22          AAAAAAAAA       3333333     0     0   ");
    puts("|  E                    22          AAAAAAAAAAA           33     0     0   ");
    puts("|  E                   22          A           A          33     0     0   ");
    puts("|. EEEEEEEEEEE       22222222     A             A    3333333     0000000   ");
    puts("                                                                       ");
    puts("|----------------------------------------------------------------------");
    puts("============================================================================");
    char word[7] = "";
    strcat(word, "F");
    puts(word);
    strcat(word, "i");
    puts(word);
    strcat(word, "g");
    puts(word);
    strcat(word, "a");
    puts(word);
    strcat(word, "r");
    puts(word);
    strcat(word, "o");
    puts(word);

    int password, attempts = 3;
    while (attempts > 0)
    {
        printf("enter the four digit password: ");
        scanf("%d", &password);
        if (password == 2025)
        {
            printf("password id correct! Welcome!\n");
            break;
        }
        else
        {
            printf("Wrong Password\n");
            attempts--;

            if (attempts == 0)
            {
                printf("Wrong password three times !\a");
                return 0;
            }
        }
    }
    char choice;
    while (1)
    {
        system("clear");
        menu();
        printf("Please enter your choice:");
        getchar();
        scanf("%c", &choice);
        getchar(); // 清空緩存

        switch (choice)
        {
        case 'a':
            system("clear");
            enter_grades();
            break;
        case 'b':
            system("clear");
            display_grades(students, student_count);
            break;
        }
    }
}
