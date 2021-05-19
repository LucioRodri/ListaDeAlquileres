#pragma once
#include "cVehiculo.h"
using namespace std;
class cTrafics :
    public cVehiculo
{
    const unsigned int cant_asientos;
    const unsigned int cant_sillas;
    static const unsigned int precio_asiento_rebatible;
    static unsigned int precio_dia;
    static const unsigned int precio_silla_ninios;
public:
    cTrafics(const unsigned int asientos, const unsigned int sillas, unsigned int capacidad, string color, tm* fecha, unsigned int chasis, string patente, unsigned int poliza, unsigned int base, unsigned int dias);
    cTrafics(cTrafics* copia);
    ~cTrafics();
    virtual float calcular_tarifa();
    virtual void pasos_mantenimiento();
    virtual unsigned int cant_elementos_seguridad();
    string to_string();
    void Imprimir();
};
