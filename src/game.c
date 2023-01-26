#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int count_of_char(char string[])
{
    int count = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] != ' ')
            count++;
    }
    return count;
}

int game(void)
{
    // TODO : parsing username to game function

    clear_screen();
    delay(500);

    char name[25], word[25];
    printf("\n   > HI , What is your name : ");
    scanf("%s", name);

    FILE *fPtr;
    fPtr = fopen("./data/words.txt", "r");
    fscanf(fPtr, "%s", word);

    // TODO : pick a randome word

    printf("\n\n    / Picking a random word \\");
    delay(500);
    for (int i = 0; i < 5; ++i)
    {
        printf(".");
        flush();
        delay(500);
    }
    delay(2000);
    clear_screen();
    printf("\n\n        ");
    for (int i = 0; i < count_of_char(word); i++)
    {
        delay(500);
        printf(" - ");
    }

    change_color_rgb(235, 225, 33);
    delay(500);
    printf("\n \n \n                                                  ### START ###");
    reset_color();
    delay(5000);
}