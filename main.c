#include <stdio.h>
#include <regex.h>
#include <string.h>
#include "./lib/clui.h"
#include "./src/pages.c"
#include "./src/game.c"
#include "./src/authentication.c"

int main(void)
{
    init_clui();

    welcome_page();

    while (1)
    {
        int user_option = main_menu_page();
        if (user_option == 3)
        {
            quit();
        }
        else if (user_option == 2)
        {
            sign_up();
        }
        else if (user_option == 1)
        {
            if (login())
            {
                while (1)
                {
                    int user_option = game_menu_page();
                    if (user_option == 4)
                    {
                        break;
                    }
                    else if (user_option == 3)
                    {
                        char word[25];
                        FILE *fPtr;
                        fPtr = fopen("./data/words.txt", "a");
                        clear_screen();
                        delay(1000);
                        printf("\n   > New word : ");
                        scanf("%s", word);
                        fprintf(fPtr, "%s\n", word);
                        fclose(fPtr);
                        delay(500);
                        change_color_rgb(41, 214, 73);
                        printf("\n\n        ** The new word added successfully ** \n");
                        reset_color();
                        delay(3000);
                    }
                    else if (user_option == 2)
                    {
                        clear_screen();
                        FILE *fPtr;
                        fPtr = fopen("./data/scores.txt", "r");
                        char c = fgetc(fPtr);
                        while (c != EOF)
                        {
                            printf("%c", c);
                            c = fgetc(fPtr);
                        }
                        fclose(fPtr);
                        printf("\n\n\n   > back to game menu");
                        getch();
                    }
                    else if (user_option == 1)
                    {
                        game();
                    }
                }
            }
        }
    }
}