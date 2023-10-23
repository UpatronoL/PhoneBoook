#include "common.h"
#include "screens.h"
#include "generalVariables.h"

int main()
{
    while(state)
    {
        switch (screens)
        {
        case INITIALIZE:
            screens = initialize();
            break;
        
        case SIGNUP:
            screens = signUp();
            break;

        case LOGIN:
            screens = logIn();
            break;
        
        case HOME:
            screens = home();
            break;

        case QUIT:
            state = 0;
            break;
        
        default:
            break;
        }
    }
    return 0;
}