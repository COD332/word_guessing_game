#include <stdio.h>
#include "clui.h"
#include "./src/pages.c"
#include "./src/authentication.c"

int main(void)
{
    init_clui();

    welcome_page();

    int user_option = main_page_menu();
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