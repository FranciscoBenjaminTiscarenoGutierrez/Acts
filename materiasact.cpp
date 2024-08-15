#include <iostream>
#include <string>
#include<windows.h>  
#include<sstream> 
using namespace std;

#define st string
#define ff float

class materia {
    private:
    int clave;
    st nombre;
    st profesor;
    st libro;
    public:
    materia(int,st,st,st);
    string getid(){st id = to_string(clave); return id;}
    void imprime(st id){cout << "Nombre: " << nombre << endl << "profesor: " << profesor << endl << "Este materia requiere el libro " << libro << endl;};
    void swapprofesor(){string _hand; getline(cin, _hand); profesor = _hand;};
    void swapreporta(){string _hand; getline(cin, _hand); profesor = _hand;};
    void swapid(){string _hand; getline(cin, _hand);int num = stoi(_hand); clave=num;};
};

materia::materia(int _clave,st _nombre,st _profesor,st _libro){
 clave = _clave;nombre = _nombre;profesor = _profesor;libro = _libro;
};

materia programacion = materia(123,"programacion","Juan flores","Introduccion a programacion");
materia basesdedatos = materia(456,"bases de datos","Perez Garcia","Diseno y bases de datos 2004");;

int empverify(st id) {
    st idd = programacion.getid();
    st idd2 = basesdedatos.getid();
    if (id == idd){return 1;};
    if (id == idd2){return 2;}
    else { cout << endl << "Clave desconocida" << endl; return 0;};
}



////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
class func{
    private:

    string commandd;
    string atribute;


        const string cmdexit ="/salir";
        const string cmdview ="/info";
        const string cmdnamep ="/cambiarprofesor";
        const string cmdid ="/cambiarclave";

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

    if (commandd == cmdview) {

        switch (empverify(atribute))
        {
        case 0: break;
        case 1: cout << "movimiento invalido\n";break; programacion.imprime(atribute);  break;
        case 2: basesdedatos.imprime(atribute);  break;
        
        default:  break;
        }
    }

    else if(commandd == cmdnamep){
        switch (empverify(atribute))
        {
        case 0: break;
        case 1: cout << "movimiento invalido\n"; break; programacion.swapprofesor();  break;
        case 2: basesdedatos.swapprofesor();  break;
        
        default:  break;
        }
    }


    else if(commandd == cmdid){
        switch (empverify(atribute))
        {
        case 0: break;
        case 1: programacion.swapid();  break;
        case 2: cout << "movimiento invalido\n";break;basesdedatos.swapid();  break;
        
        default:  break;
        }
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
cout << "|     ADMINISTRAR materiaS                     |" << endl;
cout << "+----------------------------------------------+" << endl;
cout << "|   /info-<clave>                              |" << endl;
cout << "|   * Informacion (solo bases de datos)        |" << endl;
cout << "|                                              |" << endl;
cout << "|   /cambiarprofesor-<clave>                   |" << endl;
cout << "|   * (solo bases de datos)                    |" << endl;
cout << "|                                              |" << endl;
cout << "|   /cambiarclave-<clave>                      |" << endl;
cout << "|   * (solo programacion)                      |" << endl;
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
