#include "common.h"
#include "generalVariables.h"

int initialize()
{
    initscr();
    keypad(stdscr,TRUE);
    char * options[] = {"Sign Up", "Log In", "Quit"};
    clear();
    refresh();

    getmaxyx(stdscr, yMax, xMax);
    centerText("wlcome to PhoneBook", -2);
    centerText("Pleas choose what you would like to do", -1);

    refresh();
    size = sizeof(options)/sizeof(options[0]);
    formatOptions(options, size);

    clear();
    endwin();
    if(hilight == 0)
        return 1;
    if(hilight == 1)
        return 2;
    if(hilight == 3)    
        return 4;
    return -1;
}