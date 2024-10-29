#ifndef MENUESCOLAR_H
#define MENUESCOLAR_H
#include <iostream>
#include <string>
#include <sstream>
#include "Alumno.h"
#include "LSLSE.h"
class slashmenu{
    private:
    int many=0;
    LSLSE<Alumno> lista;

    std::string commandd;
    std::string atribute;


        const std::string cmdexit ="/salir";
        const std::string insert ="/solicitud";
        const std::string process ="/constancia";
        const std::string find ="/encontrar";

    public:
    
    void commandslashmenu(std::string inn){
        char criminant = '-';  
    std::string tok;
    std::string console = inn;
    std::istringstream iss(console);
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
    if (commandd == insert) {
        Alumno nuevoAlumno; 
        std::cin >> nuevoAlumno;
        auto nodoUltimo = lista.ultimo();
        lista.insertarCola(nodoUltimo, nuevoAlumno);
        many++;
    }
    else if (commandd == process) {
        int intribute = std::stoi(atribute);
        for(int i=0;i<intribute;i++){if (!lista.vacia()) {
            lista.imprimirNodo(lista.primero());
            lista.eliminar(lista.primero());
        } else {
            std::cout << "La lista está vacia.\n";
        }}
        
    }
    /*else if (commandd == find) {
        try {
            int intribute = std::stoi(atribute);
            node<Alumno>* finded = lista.buscarPorNumeroSocio(intribute);
            lista.imprimirNodo(finded);
        } catch (const std::invalid_argument&) {
            node<Alumno>* finded = lista.buscarPorDomicilio(atribute);
            lista.imprimirNodo(finded);
        }
    }*/

    else if (commandd == cmdexit) {
        throw std::runtime_error("Saliendo del programa");
    }
    else {
        std::cout << "Comando inválido\n"; 
    }
}

    void menustart(){
        using namespace std;
cout << "+----------------------------------------------+" << endl;
cout << "|     Generador de Constancias                 |" << endl;
cout << "+----------------------------------------------+" << endl;
cout << "|   /solicitud                                 |" << endl;
cout << "|   * Inserta solicitud de un alumno a la cola |" << endl;
cout << "|                                              |" << endl;
cout << "|   /constancia-<num>                          |" << endl;
cout << "|   * Elabora una constancia                   |" << endl;
cout << "|                                              |" << endl;
cout << "|   /salir                                     |" << endl;
cout << "|   Sale del programa.                         |" << endl;
cout << "+----------------------------------------------+" << endl;
     }

};

#endif // MENUESCOLAR_H






