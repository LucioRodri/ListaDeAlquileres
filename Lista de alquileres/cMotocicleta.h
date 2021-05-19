#pragma once
#include "cVehiculo.h"
using namespace std;
class cMotocicleta :
    public cVehiculo
{
private:
    const unsigned int cascos;
    static const unsigned int precio_cascos = 750;
    static const unsigned int precio_dia = 1500;

public:
    cMotocicleta(unsigned int cascos, unsigned int precio_dia, unsigned int capacidad_pasajeros, string color,  tm* fecha, unsigned int chasis, string patente, unsigned int poliza, unsigned int base, unsigned int dias);
    cMotocicleta(cMotocicleta* copia);
    ~cMotocicleta();
    float Calcular_tarifa();
    void pasos_mantenimiento();
    virtual unsigned int cant_elementos_seguridad();
    string get_patente() { return numero_patente; }
    string to_string();
    void Imprimir();
};


