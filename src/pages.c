// welcome page
int welcome_page(void)
{
    printf("\n");
    delay(1000);
    printf("  Welcome to ");
    delay(1000);
    change_color_rgb(207, 99, 99);
    printf("WORD QUESSING");
    reset_color();
    delay(1000);
    printf(" game !");
    delay(2000);
    printf("\n\n     Game Is Louding ");
    for (int i = 0; i < 5; ++i)
    {
        change_color_rgb(236, 46, 242);
        printf("%c ", 176);
        flush();
        delay(500);

        change_color_rgb(113, 111, 252);
        printf("%c ", 176);
        flush();
        delay(100);

        change_color_rgb(111, 252, 149);
        printf("%c ", 176);
        flush();
        delay(250);

        change_color_rgb(238, 252, 111);
        printf("%c ", 176);
        flush();
        delay(500);

        change_color_rgb(252, 160, 111);
        printf("%c ", 176);
        flush();
        delay(50);
    }
    reset_color();
    delay(2000);
}

// main menu page
int main_menu_page(void)
{
    clear_screen();

    delay(1000);
    printf("\n   > 1.Login");
    delay(250);
    printf("\n   > 2.Signup");
    delay(250);
    printf("\n   > 3.Exit");

    while (1)
    {
        char key = getch();
        if (key == 72)
        {
            if (get_cursor_x() == 2)
            {
                continue;
            }
            cursor_up(1);
        }
        if (key == 80)
        {
            if (get_cursor_x() == 4)
            {
                continue;
            }
            cursor_down(1);
        }
        if (key == 13)
        {
            int curser_x_pos = get_cursor_x();

            if (curser_x_pos == 4)
            {
                // user select exit option
                return 3;
            }
            else if (curser_x_pos == 3)
            {
                // user select signup option
                return 2;
            }
            else if (curser_x_pos == 2)
            {
                // user select login option
                return 1;
            }
        }
    }
}

// game menu page
int game_menu_page(void)
{
    clear_screen();

    delay(1000);
    printf("\n   > 1.Start game");
    delay(250);
    printf("\n   > 2.Show leaderboard");
    delay(250);
    printf("\n   > 3.New word");
    delay(250);
    printf("\n   > 4.Back to main menu");

    while (1)
    {
        char key = getch();
        if (key == 72)
        {
            if (get_cursor_x() == 2)
            {
                continue;
            }
            cursor_up(1);
        }
        if (key == 80)
        {
            if (get_cursor_x() == 5)
            {
                continue;
            }
            cursor_down(1);
        }
        if (key == 13)
        {
            int curser_x_pos = get_cursor_x();

            if (curser_x_pos == 5)
            {
                return 4;
            }
            else if (curser_x_pos == 4)
            {
                return 3;
            }
            else if (curser_x_pos == 3)
            {
                return 2;
            }
            else if (curser_x_pos == 2)
            {
                return 1;
            }
        }
    }
}
