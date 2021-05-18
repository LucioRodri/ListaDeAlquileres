#pragma once
#include "cVehiculo.h"
class cMotocicleta :
    public cVehiculo
{
private:
    const unsigned int cascos;
    static const float precio_cascos;
    static unsigned int precio_dia;

public:
    cMotocicleta(unsigned int cascos, float precio_cascos, unsigned int precio_dia);
    cMotocicleta(cMotocicleta* copia);
    ~cMotocicleta();
    float Calcular_tarifa();
    void PasosMantenimiento();
};

