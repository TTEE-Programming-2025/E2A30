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
        scanf("%d", &choice);
        getchar(); //清空緩存

        switch(choice)
        {
            case 'a':
            
        }

    }
}
