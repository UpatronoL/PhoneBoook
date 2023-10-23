#include "common.h"
#include "generalVariables.h"



void formatOptions(char * options[], int size)
{
    hilight = 0;
    while(1)
    { 
        refresh();
        for(int i = 0; i < size; i++)
        {
            if(i == hilight)
                wattron(stdscr, A_REVERSE);
            centerText(options[i], i+1);
            wattroff(stdscr, A_REVERSE);
        }

        choice = getch();
        switch (choice)
        {
        case KEY_UP:
            hilight--;
            if(hilight == -1)
                hilight = size-1;
            break;
        case KEY_DOWN:
            hilight++;
            if(hilight == size)
                hilight = 0;
            break;
        default:
            break;
        }
        if(choice == 10)
           break;
    }
}

void centerText(char text[], int loc)
{
    int offset = strlen(text) / 2;
    mvprintw(yMax / 2 + loc, xMax / 2 - offset, "%s", text);
}