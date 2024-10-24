#include <iostream>
#include <string>
#include<windows.h>  
#include<sstream> 
#include "Cola.h"
using namespace std;

#define st string
#define ff float
Cola maincola;


////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
class func{
    private:

    string commandd;
    string atribute;


        const string cmdexit ="/salir";
        const string insert ="/solicitud";
        const string process ="/constancia";
        const string find ="/encontrar";
        const string sort ="/ordenar";

    public:
    
    void commandfunc(string inn){
        char criminant = '-';  
    string tok;
    string console = inn;
    istringstream iss(console);
    int i=0;
    while (getline(iss, tok, criminant)) {
        switch (i)
        {
        case 0: commandd=(tok); break;
        case 1: atribute=(tok); break;

        default:
            break;
        }

         ++i;
        
    }
    selector();
    }


void selector() {
    //if (commandd.empty()){}

    if (commandd == insert) {
        int i = std::stoi(atribute);
        maincola = maincola + i;
    }

    else if(commandd == process){
        int i = std::stoi(atribute);
        maincola = maincola - i;
    }

    else if(commandd == find){
        maincola.find(atribute);
    }
    else if(commandd == sort){
        maincola.ordenarPorPromedio();
    }


    else if(commandd == cmdexit){throw runtime_error("Saliendo del programa");}

    else {
        cout << "Comando invalido\n"; 
    };

}

    void testt (){cout << "\n  Testeo " << endl; }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char const *argv[])
 {
    
    func fum;
    string hand;

    for(;;){

cout << "+----------------------------------------------+" << endl;
cout << "|     Generador de Constancias                 |" << endl;
cout << "+----------------------------------------------+" << endl;
cout << "|   /solicitud-<num>                           |" << endl;
cout << "|   * Inserta solicitud de un alumno a la cola |" << endl;
cout << "|                                              |" << endl;
cout << "|   /constancia-<num>                          |" << endl;
cout << "|   * Elabora una constancia    1111111        |" << endl;
cout << "|                                              |" << endl;
cout << "|   /salir                                     |" << endl;
cout << "|   Sale del programa.                         |" << endl;
cout << "+----------------------------------------------+" << endl;


     getline(cin, hand);
     fum.commandfunc(hand);


     system ("PAUSE");
     system("cls");

    }
    

}
