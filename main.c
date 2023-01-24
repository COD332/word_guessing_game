#include <stdio.h>
#include "clui.h"

int main(void)
{
    init_clui();

    // welcome page
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
        printf(". ");
        flush();
        delay(500);

        change_color_rgb(113, 111, 252);
        printf(". ");
        flush();
        delay(500);

        change_color_rgb(111, 252, 149);
        printf(". ");
        flush();
        delay(500);

        change_color_rgb(238, 252, 111);
        printf(". ");
        flush();
        delay(500);

        change_color_rgb(252, 160, 111);
        printf(". ");
        flush();
        delay(500);
    }
    reset_color();
    delay(2000);
    clear_screen();
    delay(2000);
}