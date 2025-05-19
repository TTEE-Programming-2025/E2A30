#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
typedef struct
{
    char name[50];
    int id;
    int math;
    int physics;
    int english;
    float average;
} Student;
void enter_grades()
{
    int n;
    int student_count = 0;
    char name[100];
    Student students[10];
    printf("Enter number of Students(5-10):");
    scanf("%d", &n);
    while (n < 5 || n > 10)
    {
        printf("Please enter a number between 5~10");
        scanf("%d", &n);
    }
    student_count = n;

    getchar();
    for (int i = 0; i < student_count; i++)
    {
        printf("\n enter students %d name :", i + 1);
        getchar();
        fgets(students[i].name, 100, stdin);//使用fgets是因為scanf無法讀取整行字串以及空格
        printf("enter student ID(6 digits):");
        scanf("%d", &students[i].id);

        printf("Enter Math score: ");
        scanf("%d", &students[i].math);

        printf("Enter Physics score: ");
        scanf("%d", &students[i].physics);

        printf("Enter English score: ");
        scanf("%d", &students[i].english);
    }
}
int main(void)
{
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
        scanf("%c", &choice);
        getchar(); // 清空緩存

        switch (choice)
        {
        case 'a':
            enter_grades();
        }
    }
}
