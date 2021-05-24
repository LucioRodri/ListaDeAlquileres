#pragma once
#include "cVehiculo.h"
using namespace std;
class cCamioneta :
    public cVehiculo
{
private:
    static unsigned int precio_dia;
    bool portequipaje;
    static const unsigned int precio_portaequipaje;
    static const unsigned int precio_sillas;
    const unsigned int cant_silla_ninios;
public:
    cCamioneta(bool portaequipaje, unsigned int cant_silla_ninios, unsigned int capacidad, string color, tm* fecha, unsigned int chasis, string patente, unsigned int poliza, unsigned int base, unsigned int dias);
    cCamioneta(cCamioneta* copia);
    ~cCamioneta();
    float Calcular_tarifa();
    void pasos_mantenimiento();
    unsigned int cant_elementos_seguridad();
    string get_tipo() { return tipo_vehiculo; };
    string get_patente() { return numero_patente; }
    string to_string();
    void Imprimir();
};

