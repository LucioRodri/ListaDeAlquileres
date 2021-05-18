#include "cCamioneta.h"

cCamioneta::cCamioneta(unsigned int precio_dia,
	unsigned int cant_silla_ninios, bool portaequipaje): cant_silla_ninios(cant_silla_ninios)
{
	this->portequipaje = portaequipaje;
}
unsigned int precio_dia = 1500;
const unsigned int precio_portaequipaje=500;
const unsigned int precio_sillas=250;

cCamioneta::cCamioneta(cCamioneta* copia):cant_silla_ninios(copia.cant_sillas_ninios)
{
	this->portequipaje = copia->portequipaje;
}

cCamioneta::~cCamioneta()
{

}

float cCamioneta::Calcular_tarifa()
{
	if(portequipaje)
		return (/*precio_dia*dias+*/precio_base+precio_portaequipaje+precio_sillas_ninios*cant_silla_ninios);
	else
		return (/*precio_dia*dias+*/precio_base + precio_sillas_ninios * cant_silla_ninios);
}

void cCamioneta::PasosMantenimiento()
{
}
