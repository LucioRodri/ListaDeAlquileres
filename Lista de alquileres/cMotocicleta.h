#pragma once
#include "cVehiculo.h"
using namespace std;
class cMotocicleta :
    public cVehiculo
{
private:
    const unsigned int cascos;
    static const float precio_cascos;
    static unsigned int precio_dia;

public:
    cMotocicleta(unsigned int cascos, float precio_cascos, unsigned int precio_dia, unsigned int capacidad_pasajeros, string color,  tm* fecha, unsigned int chasis, string patente, unsigned int poliza, unsigned int base, unsigned int dias);
    cMotocicleta(cMotocicleta* copia);
    ~cMotocicleta();
    float Calcular_tarifa();
    void PasosMantenimiento();
    virtual unsigned int cant_elementos_seguridad();
    string to_string();
    void imprimir();
};

