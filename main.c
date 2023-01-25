// compile : gcc main.c -o game -lregex

#include <stdio.h>
#include <regex.h>
#include <string.h>
#include "./lib/clui.h"
#include "./src/pages.c"
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
        else if (user_option == 2)
        {
            /* login */
        }
    }
}