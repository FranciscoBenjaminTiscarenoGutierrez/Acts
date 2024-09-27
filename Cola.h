#ifndef COLA_H
#define COLA_H
#include <iostream>
#include <string>
const int TAM=100;

//***************************Definicion de la clase persona*************************
//**********************************************************************************
class Alumno {
private:
    std::string nombre;
    std::string carrera;
    std::string materias;
    float promedio;

public:
    Alumno() : nombre(""), carrera(""), materias(""), promedio(0.0) {}

    friend std::istream& operator>>(std::istream& hand, Alumno& alumno) {
        std::cout << "Nombre: ";
        std::getline(hand, alumno.nombre);  //Por razones que escapan a mi comprension esto debe permanecer como getline.
        std::cout << "Carrera: ";  
        hand >> alumno.carrera;
        std::cout << "Materias: ";
        hand >> alumno.materias;
        std::cout << "Promedio: ";
        hand >> alumno.promedio;
        hand.ignore(); 
        return hand;
    }

    friend std::ostream& operator<<(std::ostream& show, const Alumno& alumno) {
        show << "Nombre: " << alumno.nombre << ", Carrera: " << alumno.carrera 
             << ", Materias: " << alumno.materias << ", Promedio: " << alumno.promedio;
        return show;
    }

    std::string getname() {
        return nombre;
    }

};


//***************************************************************************************



//****************************Definicion de la clase Pila****************************
//***********************************************************************************
class Cola
{
private:
    Alumno datos[TAM];
    int ult;
    bool elimina(int pos);
    int inserta(Alumno& elem, int pos);

public:
    Cola():ult(-1){}


    bool vacia()const{return ult < 0;}
    bool llena()const{return ult >= TAM - 1;}

    friend std::ostream& operator<<(std::ostream & o, Cola& L);

    void enqueue(){

        if (llena()) {
            std::cout << "La cola esta llena, no se puede agregar mas elementos" << std::endl;
            return;
        }

        std::cout<<"valor ult" << ult <<std::endl; /////////////////////////

        std::cin.ignore(); 
        ult++;
        std::cin >>datos[ult]; 
        
    }

    Alumno& dequeue(){

        std::cout << datos[0] << std::endl;
        std::cout<<"valor ult" << ult <<std::endl; /////////////////////////
    for (int i = 0; i < ult; i++) {
        
        datos[i] = datos[i + 1];
    }
    
    ult--; 
    }

    Cola operator+(int i) const {

        Cola nuevaCola = *this; 
        for(int fi=0;fi<i;fi++){
            std::cout<<"Creando solicitud"<<std::endl; /////////////////////////
        
        nuevaCola.enqueue();   
        }
        return nuevaCola;        
    }

    Cola operator-(int i) const {

        Cola nuevaCola = *this;
        if (vacia()) {
            std::cout << "La cola esta vacia, no se puede eliminar ningun elemento" << std::endl;
            return nuevaCola;
        }
 
        for(int fi=0;fi<i;fi++){
            std::cout<<"Creando Constancia"<<std::endl; /////////////////////////
        
        nuevaCola.dequeue();   
        }
        return nuevaCola;       
    }

    int find(std::string hand){
        int i=ult;
        for(;i!=-1;i--){

            std::string temp = datos[i].getname();

            if(temp == hand){

                //std::cout<<"Encontrado "<<std::endl; /////////////////////////

                std::cout<<"Elementos delante de este "<< i<<std::endl; /////////////////////////
                return i;
            }

        }
        
    }
    


};
//*************************************************************************************

#endif // COLA_H

