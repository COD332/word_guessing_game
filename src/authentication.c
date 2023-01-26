#include <regex.h>

// Check the uniqueness of the username
int username_in_use(char username[])
{
    FILE *fPtr;
    int wordExist = 0;
    int bufferLength = 255;
    char line[bufferLength];
    fPtr = fopen("./data/uandp.txt", "r");
    while (fgets(line, bufferLength, fPtr))
    {
        char *ptr = strstr(line, username);
        if (ptr != NULL)
        {
            fclose(fPtr);
            return 1;
        }
    }
    fclose(fPtr);
    return 0;
}

// Checking password rules
// int password_validation(char password[])
// {
//     regex_t reegex;
//     int value;
//     value = regcomp(&reegex, "((?=.*\\d)(?=.*[a-z])(?=.*[A-Z])(?=.*[_+-.,!@#$^&*();\\/|<>\"']).{8,})", 0);
//     value = regexec(&reegex, password, 0, NULL, 0);
//     printf("\n%d", value);
// }

// sign up
int sign_up(void)
{
    char username[25], password[25];

    clear_screen();
    delay(500);
    printf("\n   > Please enter a unique username : ");
    scanf("%s", username);

    // cheking username
    while (username_in_use(username))
    {
        change_color_rgb(207, 99, 99);
        printf("\n        OH, THIS USER NAME IS IN USE , TRY ANOTHER ONE !");
        reset_color();
        delay(5000);
        clear_screen();
        printf("\n   > Please enter a unique username : ");
        scanf("%s", username);
    }
    delay(500);
    change_color_rgb(41, 214, 73);
    printf("\n        ** OK ** \n");
    reset_color();

    delay(1000);
    printf("\n   > Please enter a password with at least 8 characters, including lowercase and uppercase letters,\n     numbers and special characters (@, #, and ..) : ");

    // TODO : Add the possibility to delete the password and re-enter it
    // TODO : create loading animation with / | \ - ...

    for (int i = 0; i < 25; i++)
    {
        char character = getch();

        if (character == 13)
        {
            break;
        }

        printf("*");
        password[i] = character;
    }

    // writing data to file
    FILE *fPtr;
    fPtr = fopen("./data/uandp.txt", "a");

    // TODO : save sha256 form of passwprd in file

    fprintf(fPtr, "%s:%s\n", username, password);
    fclose(fPtr);
    delay(500);
    change_color_rgb(41, 214, 73);
    printf("\n\n        ** The user was successfully registered :) ** \n");
    reset_color();
    delay(3000);
    printf("\n\n    Moving to the main menu ");
    delay(500);
    for (int i = 0; i < 5; ++i)
    {
        printf(".");
        flush();
        delay(500);
    }
}

// login
int login(void)
{
    char username[25], password[25];
    clear_screen();
    delay(500);
    printf("\n   > Please enter username : ");
    scanf("%s", username);
    delay(500);
    if (!username_in_use(username))
    {
        change_color_rgb(207, 99, 99);
        printf("\n        User ID is not registered in the system; Please register it first from the main menu");
        reset_color();
        delay(5000);
        printf("\n\n    Moving to the main menu ");
        delay(500);
        for (int i = 0; i < 5; ++i)
        {
            printf(".");
            flush();
            delay(500);
        }
        return 0;
    }
    else
    {
        delay(500);
        printf("\n   > Please enter password : ");
        scanf("%s", password);

        // TODO
        // for (int i = 0; i < 25; i++)
        //{
        //     char character = getch();
        //
        //    if (character == 13)
        //    {
        //        break;
        //    }
        //    password[i] = character;
        //    printf("*");
        //}

        if (!username_in_use(strcat(strcat(username, ":"), password)))
        {
            change_color_rgb(207, 99, 99);
            printf("\n        wrong password, Please try again from the main menu");
            reset_color();
            delay(5000);
            printf("\n\n    Moving to the main menu ");
            delay(500);
            for (int i = 0; i < 5; ++i)
            {
                printf(".");
                flush();
                delay(500);
            }
            return 0;
        }
        else
        {
            delay(500);
            change_color_rgb(41, 214, 73);
            printf("\n\n        ** You have entered correctly :) ** \n");
            reset_color();
            delay(2000);
            return 1;
        }
    }
}