#include <stdio.h>

int main_page_menu(void)
{
    // main page menu
    clear_screen();

    delay(1000);
    printf("\n   > 1.Login");
    delay(500);
    printf("\n   > 2.Signup");
    delay(500);
    printf("\n   > 3.Exit");
    delay(2000);

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