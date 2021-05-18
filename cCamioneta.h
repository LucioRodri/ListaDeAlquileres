#pragma once
#include "cVehiculo.h"
class cCamioneta :
    public cVehiculo
{
private://Agregar cant de dias o mandar como parametro?
    static unsigned int precio_dia;
    bool portequipaje;
    static const unsigned int precio_portaequipaje;
    static const unsigned int precio_sillas;
    const unsigned int cant_silla_ninios;
public:
    cCamioneta(unsigned int precio_dia, unsigned int cant_silla_ninios, bool portaequipaje=false);
    cCamioneta(cCamioneta* copia);
    ~cCamioneta();
    float Calcular_tarifa();
    void PasosMantenimiento();
};
