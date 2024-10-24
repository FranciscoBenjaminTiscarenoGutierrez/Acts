#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include <sstream>
#include "LSLSE.h"
#include "socio.h"

class slashmenu{
    private:
    int many=0;
    LSLSE<SocioClub> lista;

    std::string commandd;
    std::string atribute;


        const std::string cmdexit ="/salir";
        const std::string insert ="/registrar";
        const std::string ddelete ="/baja";
        const std::string process ="/reporte";
        const std::string find ="/encontrar";
        const std::string total ="/total";

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
    //if (commandd.empty()){}

    if (commandd == insert) {

        std::string a1,a2,hand;
        int num1,num2;

         while (true) {
            std::cout << "Numero de socio: " << std::endl; 
            std::getline(std::cin, hand);
            try {
                num1 = std::stoi(hand);
                node<SocioClub>* finded = lista.buscarPorNumeroSocio(num1);
                if (finded != nullptr) {
                 std::cout << "Numero ya existente" << std::endl;
                 return; 
                }
                break; 
            } catch (const std::invalid_argument&){std::cout << "Ingrese un numero" << std::endl;}
        } 
        std::cout << "Nombre: " << std::endl;
        std::getline(std::cin, a1); 
        std::cout << "Domicilio: " << std::endl;
        std::getline(std::cin, a2); 
        while (true) {
            std::cout << "Fecha de ingreso: " << std::endl;
            std::getline(std::cin, hand);
            try {
                num2 = std::stoi(hand);
                break; 
            } catch (const std::invalid_argument&){std::cout << "Ingrese un numero" << std::endl;}
        }
        SocioClub thissocio(num1,a1,a2,num2);



        lista.insertar(lista.ultimo(), thissocio);
        lista.ordenar();
        many++;
    }

    else if(commandd == process){
        lista.imprimir();
    }

    else if(commandd == find){

    try {

        int intribute = std::stoi(atribute);
        node<SocioClub>* finded = lista.buscarPorNumeroSocio(intribute);
        lista.imprimirNodo(finded);
        
    } catch (const std::invalid_argument&) {
        node<SocioClub>* finded = lista.buscarPorDomicilio(atribute);
        lista.imprimirNodo(finded);
    }


    }
    else if(commandd == ddelete){

    try {
    int intribute = std::stoi(atribute);
    node<SocioClub>* finded = lista.buscarPorNumeroSocio(intribute);

    if (finded != nullptr){
        bool eliminado = lista.eliminar(finded);
        if (eliminado) {
            std::cout << "Eliminado exitosamente " << std::endl;many--;
        } else {
            std::cout << "Error al eliminar" << std::endl;
        }
    } 
    else {
        std::cout << "No se encontro tal socio" << std::endl;
    }
   } 
catch (const std::invalid_argument&) {
    node<SocioClub>* finded = lista.buscarPorDomicilio(atribute);

    if (finded != nullptr) {
        bool eliminado = lista.eliminar(finded);  
        if (eliminado) {
            std::cout << "Eliminado exitosamente " << std::endl;many--;
        } else {
            std::cout << "Error al eliminar" << std::endl;
        }
    } 
    else {
        std::cout << "No se encontro tal socio" << std::endl;
    }
  }



        
    }
    else if(commandd == total){
        std::cout << "Total de socios: "<< many <<std::endl;

    }
    else if(commandd == cmdexit){throw std::runtime_error("Saliendo del programa");}

    else {
        std::cout << "Comando invalido\n"; 
    };

}

    void menustart(){
    std::cout << "=====================================" << std::endl;
    std::cout << "   Administrar socios            " << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "| /registrar                        |" << std::endl;
    std::cout << "| /baja-<numero s.><direccion>      |" << std::endl;
    std::cout << "| /reporte                          |" << std::endl;
    std::cout << "| /encontrar-<numero s.><direccion> |" << std::endl;
    std::cout << "| /total                            |" << std::endl;
    std::cout << "| /salir                            |" << std::endl;
    std::cout << "=====================================" << std::endl;
     }

};






#endif // MENU_H






