#include "common.h"
#include "generalVariables.h"

void uploadToFile(userPoint point)
{
    FILE * file;
    file = fopen("users.txt", "a");
    if(file == NULL)
        exit(12);
    fprintf(file, "%s %s %s %s %s\n", point -> gmail, point -> password, point -> firstName, point -> secondName, point -> phonenumber);
}

int gmailValidility(userPoint point)
{
    for(int i = 0; i < strlen(point -> gmail); i++)
    {
        if(point -> gmail[i] == '@')
            return 1;
    }
    return 0;
}

int duplicateGmailCheck(userPoint point)
{
    FILE * file;
    user check;
    file = fopen("users.txt", "r");
    if(file == NULL)
        exit(12);
    while(fscanf(file,"%s %s %s %s %s", check.gmail, check.password, check.firstName, check.secondName, check.phonenumber) == 5)
    {
        if(strcmp(check.gmail, point -> gmail) == 0)
            return 1;
    }
    return 0;
}