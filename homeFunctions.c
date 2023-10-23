#include "common.h"
#include "generalVariables.h"
#include "homeVariables.h"


/* Sets all elements of array \0. Clear out the array*/
void claerStruct(userPoint use)
{
    memset(use -> firstName, '\0', sizeof(use -> firstName));
    memset(use -> secondName, '\0', sizeof(use -> secondName));
    memset(use -> phonenumber, '\0', sizeof(use -> phonenumber));
    memset(use -> gmail, '\0', sizeof(use -> gmail));
}

void findUser(userPoint use, char gmailId[20])
{
    FILE * check;
    check = fopen("users.txt", "r");
    if(check == NULL)
        exit(424);
    while (fscanf(check, "%s %s %s %s %s", use->gmail, use->password, use->firstName, use->secondName, use->phonenumber) == 5)
        if(strcmp(gmailId, use->gmail) == 0)
            break;
    fclose(check);
}

void createFile(char name[])
{
    FILE * contacts;
    char path[] = "/Users/lukakirtadze/Desktop/C_work/PhoneBook/UsersContacts/";
    strcat(fileName, path);
    strcat(fileName, name);
    strcat(fileName, ".txt");
    contacts = fopen(fileName, "a");
    if(contacts == NULL)
        exit(420);
    fclose(contacts);
}

void createContact(userPoint use)
{
    initscr();
    clear();
    refresh();
    keypad(stdscr, TRUE);

    mvprintw(yMax/2-1, (xMax-20)/2, "Enter your New contacts information");
    mvprintw(yMax/2+1, (xMax-10)/2, "Name: ");
    scanw("%s", use -> firstName);
    mvprintw(yMax/2+2, (xMax-10)/2, "Surname: ");
    scanw("%s", use -> secondName);
    mvprintw(yMax/2+3, (xMax-10)/2, "Phone Number: ");
    scanw("%s", use -> phonenumber);
    mvprintw(yMax/2+4, (xMax-10)/2, "gmail: ");
    scanw("%s", use -> gmail);
    refresh();
    clear();
    endwin();
}

void addContact(userPoint use)
{
    FILE * file = NULL;
    file = fopen(fileName, "a");
    if(file == NULL)
        printf("stop");
    fprintf(file, "%s %s %s %s\n", use -> firstName, use -> secondName, use -> phonenumber, use -> gmail);
    fclose(file);
}

int checkExistance(char phoneNumber[])
{
    FILE * check;
    check = fopen(fileName, "r");
    if(check == NULL)
        exit(424);
    while (fscanf(check, "%s %s %s %s ",reusable.firstName, reusable.secondName, reusable.phonenumber, reusable.gmail) == 4)
        if(strcmp(phoneNumber, reusable.phonenumber) == 0)
            return 1;
    return 0;
}

void deleteFunction(char phone[30])
{
    char * fileInfo = (char *) malloc(500 * sizeof(char));
    FILE * file = fopen(fileName, "r");
    if (file == NULL) exit(424);
    while (fscanf(file, "%s %s %s %s ",reusable.firstName, reusable.secondName, reusable.phonenumber, reusable.gmail) == 4)
    {
        if(strcmp(phone, reusable.phonenumber) != 0)
        {
            strcat(fileInfo, reusable.firstName);
            strcat(fileInfo, " ");
            strcat(fileInfo, reusable.secondName);
            strcat(fileInfo, " ");
            strcat(fileInfo, reusable.phonenumber);
            strcat(fileInfo, " ");
            strcat(fileInfo, reusable.gmail);
            strcat(fileInfo, "\n");
        }
    }
    fclose(file);
    freopen(fileName, "w", file);
    fprintf(file, "%s", fileInfo);
    fclose(file);
    free(fileInfo);
}

void deleteContact()
{
    char phoneNumber[30];
    initscr();
    clear();
    refresh();
    centerText("pleas enter contacts phone number", -1);
    centerText("Phone Number: ", 1);
    scanw("%s", phoneNumber);
    if (checkExistance(phoneNumber) == 0)
    {
        clear();
        refresh();
        centerText("This contact does not exit", 1);
        printw("%s", phoneNumber);
        refresh();
        getchar();
        endwin();
        return;
    }
    deleteFunction(phoneNumber);
    refresh();
    clear();
    endwin();   
}

void ediProfileInfo()
{
    char * fileInfo = (char *) malloc(500 * sizeof(char));
    char gmail[20], oldInfo[20];
    char * options[] = {"Gmail", "Password", "Phonenumber"};
    FILE * file = fopen("users.txt", "r");
    FILE * fileLogin = fopen("logedin.txt", "r");
    if (file == NULL || fileLogin == NULL) exit(424);
    fscanf(fileLogin, "%s", gmail);
    while(fscanf(file, "%s %s %s %s %s", reusable.gmail, reusable.password, reusable.firstName, reusable.secondName, reusable.phonenumber) == 5)
        if(strcmp(gmail, reusable.gmail) == 0)
            break;
    while(fscanf(file, "%s %s %s %s %s", reuse.gmail, reuse.password, reuse.firstName, reuse.secondName, reuse.phonenumber) == 5)
        if(strcmp(gmail, reuse.gmail) != 0)
        {
            strcat(fileInfo, reusable.gmail);
            strcat(fileInfo, " ");
            strcat(fileInfo, reuse.password);
            strcat(fileInfo, " ");
            strcat(fileInfo, reusable.firstName);
            strcat(fileInfo, " ");
            strcat(fileInfo, reusable.secondName);
            strcat(fileInfo, " ");
            strcat(fileInfo, reusable.phonenumber);
            strcat(fileInfo, "\n");
        }
    free(fileInfo);
    initscr();
    clear();

    refresh();
    centerText("What would you like to change in your profile", -1);
    formatOptions(options, 5);

    switch (hilight)
    {
        case 0:
            clear();
            strcpy(oldInfo, reusable.gmail);
            mvprintw(yMax / 2 - 2, (xMax - 18) / 2, "Your current Gmail: %s", reusable.gmail);
            centerText("What would you like to change your email to", -1);
            mvprintw(yMax / 2, (xMax - 10) / 2, "New Gmail: ");
            scanw("%s", &reusable.gmail);
            break;
        case 1:
            clear();
            strcpy(oldInfo, reusable.password);
            mvprintw(yMax / 2 - 2, (xMax - 18) / 2, "Your current Password: %s", reusable.password);
            centerText("What would you like to change your password to", -1);
            mvprintw(yMax / 2, (xMax - 10) / 2, "New Passowrd: ");
            scanw("%s", &reusable.password);
            break;
        case 2:
            clear();
            strcpy(oldInfo, reusable.phonenumber);
            mvprintw(yMax / 2 - 2, (xMax - 18) / 2, "Your current Phone Number: %s", reusable.phonenumber);
            centerText("What would you like to change your email to", -1);
            mvprintw(yMax / 2, (xMax - 10) / 2, "New Phone Number: ");
            scanw("%s", &reusable.phonenumber);
            break;
        default:
            break;
    }

    refresh();
    clear();
    endwin();
}