#include "common.h"
#include "generalVariables.h"
#include "logInVariables.h"

int logIn()
{
    initscr();
    clear();
    refresh();
    FILE * file = NULL;
    count = 0;
    getmaxyx(stdscr, yMax, xMax);
    centerText("Welcom to dear user", -2);
    centerText("pleas fill out the following information to log in ", -1);
    mvprintw(yMax/2+1, (xMax - 10)/2, "Gmail: ");
    scanw("%s", userLog);
    mvprintw(yMax/2+2, (xMax - 10)/2, "Password: ");
    scanw("%s", passLog);

    flagIn = checkInfo(userLog, passLog);
    while(flagIn == 0)
    {
        clear();
        refresh();
        centerText("Login failed", -3);
        centerText("passowrd or email does not mach", -2);
        centerText("pleas try again", -1);
        centerText("Gmail: ", +1);
        scanw("%s", userLog);
        centerText("Password: ", +2);
        scanw("%s", passLog);
        count++;
        if(count == 3)
        {
            clear();
            refresh();
            centerText("Login failed to may times", -3);
            centerText("We will be returning back to initialization screen", -2);
            getch();
            return 0;
        }
        flagIn = checkInfo(userLog, passLog);
    }

    file = fopen("logedin.txt", "w");
    if(file == NULL)
        exit(420);
    fprintf(file, "%s %s", userLog, passLog);
    fclose(file);

    clear();
    endwin();

    if(flagIn == 1)
        return 3;
    
    return -2;
}