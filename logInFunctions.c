#include "common.h"
#include "generalVariables.h"
#include "logInVariables.h"

int checkInfo(char gmailLog[20], char passLog[20])
{
    FILE * check;
    user fuck;
    check = fopen("users.txt", "r");
    if(check == NULL)
        exit(424);
    while (fscanf(check, "%s %s %s %s %s", fuck.gmail, fuck.password, fuck.firstName, fuck.secondName, fuck.phonenumber) == 5)
        if(strcmp(gmailLog, fuck.gmail) == 0 && strcmp(passLog, fuck.password) == 0)
            return 1;
    return 0;
}