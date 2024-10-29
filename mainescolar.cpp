#include <iostream>
#include <string>
#include "Alumno.h"
#include "menuescolar.h"
#include <limits>


int main()
{
    slashmenu mainmenu;
    std::string hand;

    for(;;){
        mainmenu.menustart();
        getline(std::cin, hand);
        mainmenu.commandslashmenu(hand);
        system ("PAUSE");
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("cls");
    }
    mainmenu.menustart();
    return 0;
};
 
