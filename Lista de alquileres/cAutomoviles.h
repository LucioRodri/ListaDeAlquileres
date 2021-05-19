#pragma once
#include "cVehiculo.h"
#include "Funciones.h"
using namespace std;
class cAutomoviles :
    public cVehiculo
{
private:
    const unsigned int cant_sillas;
    static const unsigned int precio_dia;
    static const unsigned int precio_sillas;
public:
    cAutomoviles(unsigned int cant_sillas, unsigned int capacidad_pasajeros, string color, tm* fecha, unsigned int chasis, string patente,
    unsigned int poliza, unsigned int base, unsigned int dias);
    cAutomoviles(cAutomoviles* copia);
    ~cAutomoviles();
    float Calcular_tarifa();
    void PasosMantenimiento();
    unsigned int cant_elementos_seguridad();
    string to_string();
    void imprimir();
};

