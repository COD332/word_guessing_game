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
    int word_character_count = count_of_char(word);
    for (int i = 0; i < word_character_count; i++)
    {
        delay(500);
        printf(" - ");
    }

    change_color_rgb(235, 225, 33);
    delay(500);
    printf("\n \n \n                                                  3 ");
    delay(500);
    printf("  2 ");
    delay(500);
    printf("   1 ");
    delay(500);
    change_color_rgb(69, 204, 76);
    printf("\n                                                  ### START ###");
    reset_color();
    printf("\n");
    int user_win = 0;
    int chance = 0;
    int true_characters = 0;
    if (word_character_count < 8)
    {
        for (int i = 0; i < 5; i++)
        {
            char character;
            int true_character = 0;
            scanf("%c", &character);
            for (int j = 0; j < word_character_count; j++)
            {
                if (word[j] == character)
                {
                    true_characters++;
                    true_character = 1;
                    printf(" -* %c *- ", character);
                }
            }
            if (!true_character)
            {
                chance++;
            }
        }
        if (chance < 5 && true_characters == word_character_count)
        {
            user_win = 1;
        }
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            char character;
            int true_character = 0;
            scanf("%c", &character);
            for (int j = 0; j < word_character_count; j++)
            {
                if (word[j] == character)
                {
                    true_characters++;
                    true_character = 1;
                    printf(" -* %c *- ", character);
                }
            }
            if (!true_character)
            {
                chance++;
            }
        }
        if (chance < 10 && true_characters == word_character_count)
        {
            user_win = 1;
        }
    }

    if (user_win)
    {
        clear_screen();
        change_color_rgb(69, 204, 76);
        printf("\n                                                  ### YOU WIN ###");
        reset_color();
        FILE *fPtr;
        fPtr = fopen("./data/scores.txt", "a");
        fprintf(fPtr, "%s .................... %d", name, word_character_count);
    }
    else
    {
        clear_screen();
        change_color_rgb(207, 99, 99);
        printf("\n                                                  ### YOU LOSE ###");
    }

    delay(5000);
}