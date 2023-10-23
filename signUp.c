#include "common.h"
#include "generalVariables.h"
#include "signUpVar.h"

int signUp()
{
    char * opt[2] = {"Yes", "No"};
    initscr();
    keypad(stdscr, TRUE);
    clear();
    refresh();

    luka.firstName[0] = '\0';
    luka.secondName[0] = '\0';
    luka.gmail[0] = '\0';
    luka.password[0] = '\0';
    luka.phonenumber[0] = '\0';

    clear();
    refresh();

    getmaxyx(stdscr, yMax, xMax);
    centerText("wlcome to the sign up screen", -2);
    centerText("Pleas fill out the following information", -1);

    mvprintw(yMax/2+1, (xMax-8)/2, "Name: ");
    scanw("%s", luka.firstName);
    mvprintw(yMax/2+2, (xMax-8)/2, "Surname: ");
    scanw("%s", luka.secondName);
    mvprintw(yMax/2+3, (xMax-8)/2, "Gmail: ");
    scanw("%s", luka.gmail);
    mvprintw(yMax/2+4, (xMax-8)/2, "Password: ");
    scanw("%s", luka.password);
    mvprintw(yMax/2+5, (xMax-8)/2, "Phone Number: ");
    scanw("%s", luka.phonenumber);

    clear();
    refresh();

    if(strlen(luka.firstName) == 0 || strlen(luka.secondName) == 0 || strlen(luka.gmail) == 0 || strlen(luka.password) == 0 || strlen(luka.phonenumber) == 0)
    {
        centerText("Sign up Failed", -2);
        centerText("Pleas fill out the missing information", -1);

        while(strlen(luka.firstName) == 0)
        {
            refresh();
            mvprintw(yMax/2+1, (xMax-8)/2, "Name: ");
            scanw("%s", luka.firstName);
        }

        while(strlen(luka.secondName) == 0)
        {
            refresh();
            mvprintw(yMax/2+1, (xMax-8)/2, "Surname: ");
            scanw("%s", luka.secondName);
        }

        while(strlen(luka.gmail) == 0)
        {
            refresh();
            mvprintw(yMax/2+1, (xMax-8)/2, "Gmail: ");
            scanw("%s", luka.gmail);
        }

        while(strlen(luka.password) == 0)
        {
            refresh();
            mvprintw(yMax/2+1, (xMax-8)/2, "Password: ");
            scanw("%s", luka.password);
        }

        while(strlen(luka.phonenumber) == 0)
        {
            refresh();
            mvprintw(yMax/2+1, (xMax-8)/2, "Phone Number: ");
            scanw("%s", luka.phonenumber);
        }
    }

    flag = gmailValidility(point);

    while(flag == 0)
    {
        clear();
        refresh();
        centerText("Sign up Failed", -3);
        centerText("You have entered an invalid gmail", -2);
        centerText("Pleas enter a new gmail", -1);
        mvprintw(yMax/2+1, (xMax-8)/2, "Gmail: ");
        scanw("%s", luka.gmail);
        flag = gmailValidility(point);
    }

    flag = 0;
    flag = duplicateGmailCheck(point);

    while(flag == 1)
    {
        centerText("Sign up Failed", -3);
        centerText("This gmail has alerady been used", -2);
        centerText("Pleas enter a new gmail", -1);
        mvprintw(yMax/2+1, (xMax-8)/2, "Gmail: ");
        scanw("%s", luka.gmail);
        flag = duplicateGmailCheck(point);
    }

    uploadToFile(point);

    clear();

    centerText("Sign up was successfull!", -3);
    centerText("Congragulations on becoming PhoneBook user", -2);
    centerText("Would you like to log in?", -1);

    refresh();

    size = sizeof(opt)/sizeof(opt[0]);
    formatOptions(opt, size);

    printw("%d", hilight);

    endwin();

    if(hilight == 1)
        return 0;
    if(hilight == 0)
        return 2;

    return -1;
}