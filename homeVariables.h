enum Options {ADD_CONTACT,
            DELLITE_CONTACT, 
            EDDIT_PROFILE_INFO,
            EDIT_CONTACT_INFO, 
            SEARCH_FOR_CONTACT,
            LOGOUT};

int stateHome;
char gmailId[20];
char fileName[100];
user yle, contact, reusable, reuse;
userPoint puchu, contactPoint;


void findUser(userPoint use, char []);
void createFile(char []);
void createContact(userPoint);
void ediProfileInfo();
void editContactInfo(userPoint);
int checkExistance(char []);
void deleteFunction(char []);
void deleteContact();
void serchForContact(userPoint);
void addContact(userPoint use);
void claerStruct(userPoint use);