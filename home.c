#include "common.h"
#include "generalVariables.h"
#include "homeVariables.h"

int home()
{
    stateHome = 1;
    puchu = &yle;
    contactPoint = &contact;
    char * options[] = {"Add Contac", "Dellite Contact", "Eddit Profile Info", "Eddit Contact info", "Search For Contact", "Log Out"};

    FILE * userId = NULL;
    userId = fopen("logedin.txt", "r");
    if(userId == NULL)
        exit(420);
    fscanf(userId, "%s", gmailId);
    findUser(puchu, gmailId);
    createFile(gmailId);
    
    while(stateHome)
    {
        initscr();
        keypad(stdscr, TRUE);

        clear();
        refresh();
        getmaxyx(stdscr, yMax, xMax);
        centerText("Welcome to the home screen", -2);
        centerText("pleas pick what you would like to do", -1);

        size = sizeof(options) / sizeof(options[0]);
        formatOptions(options, size);

        switch (hilight)
        {
        case ADD_CONTACT:
            claerStruct(contactPoint);
            createContact(contactPoint);
            addContact(contactPoint);
            break;

        case DELLITE_CONTACT:
            deleteContact();
            break;

        case EDDIT_PROFILE_INFO:
            ediProfileInfo();
            break;

        case EDIT_CONTACT_INFO:
            break;

        case SEARCH_FOR_CONTACT:
            break;

        case LOGOUT:
            clear();
            endwin();
            stateHome = 0;
            break;

        default:
        break;
        }
    }
    return 0;
}

