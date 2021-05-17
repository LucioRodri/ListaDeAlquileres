#pragma once
#include "cVehiculo.h"
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
    cCamioneta(bool portaequipaje, unsigned int precio_dia, unsigned int cant_silla_ninios);
    cCamioneta(cCamioneta* copia);
    ~cCamioneta();
    float Calcular_tarifa();
    void PasosMantenimiento();
};

