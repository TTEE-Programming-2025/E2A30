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
        if (students[i].physics < 0 || students[i].physics > 100)
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
    printf("\nPress Enter to continue...");
    getchar();
    getchar(); // 兩次 getchar() 是為了確保讀取換行符
}

void search_student(Student students[], int student_count)
{
    char search_name[50];
    printf("Enter student name to search: ");
    getchar();  // 清除緩衝區中的換行符
    fgets(search_name, 50, stdin);
    search_name[strcspn(search_name, "\n")] = '\0';  // 移除換行符號

    int found = 0;
    for (int i = 0; i < student_count; i++)
    {
        if (strcmp(students[i].name, search_name) == 0)
        {
            float average = (students[i].math + students[i].physics + students[i].english) / 3.0;
            printf("\nName: %s\nID: %d\nMath: %d\nPhysics: %d\nEnglish: %d\nAverage: %.1f\n",
                   students[i].name, students[i].id, students[i].math,
                   students[i].physics, students[i].english, average);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Student not found.\n");
    }

    printf("\nPress Enter to continue...");
    getchar();
}

void rank_students(Student students[], int student_count)
{
    // 建立副本，避免修改原始資料
    Student sorted_students[10];
    memcpy(sorted_students, students, sizeof(Student) * student_count);

    // 冒泡排序，依照平均分數從高到低排序
    for (int i = 0; i < student_count - 1; i++)
    {
        for (int j = 0; j < student_count - i - 1; j++)
        {
            float avg1 = (sorted_students[j].math + sorted_students[j].physics + sorted_students[j].english) / 3.0;
            float avg2 = (sorted_students[j + 1].math + sorted_students[j + 1].physics + sorted_students[j + 1].english) / 3.0;

            if (avg1 < avg2)  // 若前者平均分數小於後者，交換順序
            {
                Student temp = sorted_students[j];
                sorted_students[j] = sorted_students[j + 1];
                sorted_students[j + 1] = temp;
            }
        }
    }

    // 顯示排序後的成績
    printf("\nRanking by Average Score:\n");
    printf("Name    ID      Math  Physics  English  Average\n");
    for (int i = 0; i < student_count; i++)
    {
        float average = (sorted_students[i].math + sorted_students[i].physics + sorted_students[i].english) / 3.0;
        printf("%s %d %d %d %d %.1f\n",
               sorted_students[i].name, sorted_students[i].id, sorted_students[i].math,
               sorted_students[i].physics, sorted_students[i].english, average);
    }

    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}

void exit_system()
{
    char confirm;
    while (1)
    {
        printf("\nAre you sure you want to exit? (y/n): ");
        scanf(" %c", &confirm);

        if (confirm == 'y' || confirm == 'Y')
        {
            printf("Exiting system...\n");
            exit(0);
        }
        else if (confirm == 'n' || confirm == 'N')
        {
            printf("Returning to main menu...\n");
            break;
        }
        else
        {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
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
        scanf(" %c", &choice);

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
        case 'c':
            system("clear");
            search_student(students, student_count);
            break;
        case 'd':
            system("clear");
            rank_students(students, student_count);
            break;
        case 'e':
            exit_system();
            break;
        }
    }
}/*在這次程式設計中，我學習到如何將程式劃分為不同的模組，並透過函式來進行封裝，使整體程式結構更加清晰。在排序功能中，我理解了冒泡排序的基本原理，同時發現了其效率瓶頸。
此外，在搜尋功能中，我學習到如何使用 strcmp() 進行字串比對，並注意到輸入時 \n 符號可能導致比對失敗，這也教會我如何有效處理緩衝區中的換行符。
*/