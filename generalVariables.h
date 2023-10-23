#define SIZE 30

typedef struct User
{
    char firstName[SIZE];
    char secondName[SIZE];
    char gmail[SIZE];
    char password[SIZE];
    char phonenumber[SIZE];
}user;

typedef user * userPoint;

int xMax, yMax, size;
int hilight, choice;
int initialize();
int signUp();
int logIn();
int home();
void formatOptions(char * [], int);
void centerText(char text[], int loc);
