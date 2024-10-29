#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include <string>
const int TAM=100;

//***************************Definicion de la clase persona*************************
//**********************************************************************************
class Alumno{
private:
    std::string nombre;
    std::string carrera;
    std::string materias;
    float promedio;
public:
    Alumno() : nombre(""), carrera(""), materias(""), promedio(0.0) {}

//                          (     >>     )
    friend std::istream& operator>>(std::istream& hand, Alumno& alumno) {

        std::cout << "Nombre: ";
        std::getline(hand, alumno.nombre);
        std::cout << "Carrera: ";  
        hand >> alumno.carrera;
        std::cout << "Materias: ";
        hand >> alumno.materias;
        std::cout << "Promedio: ";
        hand >> alumno.promedio;
        hand.ignore(); 
        return hand;
    }
//                          (     <<     )
    friend std::ostream& operator<<(std::ostream& show, const Alumno& alumno) {
    show << "Nombre: " << alumno.nombre 
         << ", Carrera: " << alumno.carrera 
         << ", Materias: " << alumno.materias 
         << ", Promedio: " << alumno.promedio;

    return show;
}
//                          (     <     )
    friend bool operator<(const Alumno& a1, const Alumno& a2) {
        return a1.promedio < a2.promedio;
    }
//                          (     <=     )
    friend bool operator<=(const Alumno& a1, const Alumno& a2) {
        return a1.promedio <= a2.promedio;
    }
    std::string getname() {
        return nombre;}

};

#endif // ALUMNO_H




