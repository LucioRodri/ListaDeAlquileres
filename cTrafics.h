#pragma once
#include "cVehiculo.h"
using namespace std;
class cTrafics :
    public cVehiculo
{
    const unsigned int cant_asientos;
    const unsigned int cant_sillas;
    static const unsigned int precio_asiento_rebatible;
    static const unsigned int precio_dia;
    static const unsigned int precio_silla_ninios;
public:
    cTrafics(const unsigned int asientos, const unsigned int sillas);
    ~cTrafics();
    virtual float calcular_tarifa();
    virtual void pasos_mantenimiento();
};