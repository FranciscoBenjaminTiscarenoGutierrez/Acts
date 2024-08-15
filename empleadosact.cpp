#include <iostream>
#include <string>
#include<windows.h>  
#include<sstream> 
using namespace std;

#define st string
#define ff float

class empleado {
    private:
    int clave;
    st nombre;
    st domicilio;
    ff sueldo;
    st reportaA;
    public:
    empleado(int,st,st,ff,st);
    string getid(){st id = to_string(clave); return id;}
    void imprime(st id){cout << "Nombre: " << nombre << endl << "Domicilio: " << domicilio << endl << "Sueldo: " << sueldo << " Mensuales" << endl << "Este empleado reporta a " << reportaA << endl;};
    void swapdomicilio(){string _hand; getline(cin, _hand); domicilio = _hand;};
    void swapsueldo(){string _hand; getline(cin, _hand);  ff num = stof(_hand); sueldo = num;}; 
    void swapreporta(){string _hand; getline(cin, _hand); domicilio = _hand;};
};

empleado::empleado(int _clave,st _nombre,st _domicilio,ff _sueldo,st _reportaA){
 clave = _clave;nombre = _nombre;domicilio = _domicilio;sueldo = _sueldo;reportaA = _reportaA;
};

empleado jefeplanta = empleado(123,"Alejando","Calle flores 123",45000.1,"Maria");
empleado jefepersonal = empleado(456,"Marcos","Calle lagos 123",30000.3,"Ernesto");;

int empverify(st id) {
    st idd = jefeplanta.getid();
    st idd2 = jefepersonal.getid();
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
        const string cmddom ="/cambiardomicilio";
        const string cmdgreed ="/cambiarsueldo";
        const string cmdreport ="/cambiarreporta";

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
        case 1: jefeplanta.imprime(atribute);  break;
        case 2: jefepersonal.imprime(atribute);  break;
        
        default:  break;
        }
    }

    else if(commandd == cmddom){
        switch (empverify(atribute))
        {
        case 0: break;
        case 1: jefeplanta.swapdomicilio();  break;
        case 2: jefepersonal.swapdomicilio();  break;
        
        default:  break;
        }
    }

    else if(commandd == cmdgreed){
        switch (empverify(atribute))
        {
        case 0: break;
        case 1: jefeplanta.swapdomicilio();  break;
        case 2: jefepersonal.swapdomicilio();  break;
        
        default:  break;
        }
    }


    else if(commandd == cmdreport){
        switch (empverify(atribute))
        {
        case 0: break;
        case 1: jefeplanta.swapreporta();  break;
        case 2: jefepersonal.swapreporta();  break;
        
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
cout << "|     ADMINISTRAR EMPLEADOS                    |" << endl;
cout << "+----------------------------------------------+" << endl;
cout << "|   /info-<clave>                              |" << endl;
cout << "|   * Muestra informacion sobre el empleado    |" << endl;
cout << "|                                              |" << endl;
cout << "|   /cambiardomicilio-<clave>                  |" << endl;
cout << "|   * Cambia la direccion del empleado         |" << endl;
cout << "|                                              |" << endl;
cout << "|   /cambiarsueldo-<clave>                     |" << endl;
cout << "|   * Cambia el sueldo del empleado            |" << endl;
cout << "|                                              |" << endl;
cout << "|   /cambiarreporta-<clave>                    |" << endl;
cout << "|   * Cambia el reporte del empleado           |" << endl;
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

