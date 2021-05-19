#pragma once
#include "cVehiculo.h"
using namespace std;
class cAutomoviles :
    public cVehiculo
{
private:
    const unsigned int cant_sillas;
    static const unsigned int precio_dia = 1500;
    static const unsigned int precio_sillas = 750;
public:
    cAutomoviles(unsigned int cant_sillas, unsigned int capacidad_pasajeros, string color, tm* fecha, unsigned int chasis, string patente,
    unsigned int poliza, unsigned int base, unsigned int dias);
    cAutomoviles(cAutomoviles* copia);
    ~cAutomoviles();
    float Calcular_tarifa();
    void pasos_mantenimiento();
    unsigned int cant_elementos_seguridad();
    string get_patente() { return numero_patente; }
    string to_string();
    void Imprimir();
};

