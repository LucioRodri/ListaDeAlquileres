#pragma once
#include "cVehiculo.h"
using namespace std;
class cTrafics :
    public cVehiculo
{
    const unsigned int cant_asientos;
    const unsigned int cant_sillas;
    static const unsigned int precio_asiento_rebatible =10;
    static const unsigned int precio_dia =15;
    static const unsigned int precio_silla_ninios =20;
public:
    cTrafics(const unsigned int asientos, const unsigned int sillas, unsigned int capacidad, string color, tm* fecha, unsigned int chasis, string patente, unsigned int poliza, unsigned int base, unsigned int dias);
    cTrafics(cTrafics* copia);
    ~cTrafics();
    virtual float calcular_tarifa();
    virtual void pasos_mantenimiento();
    virtual unsigned int cant_elementos_seguridad();
    string get_patente() { return numero_patente; }
    string to_string();
    void Imprimir();
};
