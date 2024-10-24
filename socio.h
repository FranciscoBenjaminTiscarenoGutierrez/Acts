#ifndef SOCIO_H
#define SOCIO_H
#include <iostream>
#include <string>

class SocioClub {
private:
    int numerosocio;
    std::string nombresocio;
    std::string domicilio;
    int fechaingreso;

public:

    SocioClub() : numerosocio(0), nombresocio("Desconocido"), domicilio("N/A"), fechaingreso(0) {}


    SocioClub(int numerosocio, const std::string& nombresocio, const std::string& domicilio,int fechaingreso)
        : numerosocio(numerosocio), nombresocio(nombresocio), domicilio(domicilio), fechaingreso(fechaingreso) {}



        //                                           (<)
    bool operator<(const SocioClub& otro) const {
        return numerosocio < otro.numerosocio;
    }

    //                                               (>)
    bool operator>(const SocioClub& otro) const {
        return numerosocio > otro.numerosocio;
    }

    //                                               (==)
    bool operator==(const SocioClub& otro) const {
        return numerosocio == otro.numerosocio;
    }

    //                                               (!=)
    bool operator!=(const SocioClub& otro) const {
        return !(*this == otro); 
    }


    //                                              (<<)
    friend std::ostream& operator<<(std::ostream& os, const SocioClub& socio) {
    os << "Numerosocio: " << socio.numerosocio 
       << ", Nombresocio: " << socio.nombresocio 
       << ", Domicilio: " << socio.domicilio 
       << ", Fecha de ingreso: " << socio.fechaingreso;
    return os;
}

    std::string getDomicilio() const {
        return domicilio;
    }
     int getNumeroSocio() const {
        return numerosocio;
    }


};


#endif // SOCIO_H



