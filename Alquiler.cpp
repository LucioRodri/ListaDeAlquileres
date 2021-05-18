#include "Alquiler.h"

Alquiler::Alquiler(unsigned int cant_elementos_seguridad, tm fecha_inicio, tm fin_reserva, unsigned int monto_total)
{
	this->cant_elementos_seguridad = cant_elementos_seguridad;
	this->fecha_inicio = fecha_inicio;
	this->fin_reserva = fin_reserva;
	this->monto_total = monto_total;
}

Alquiler::~Alquiler()
{
}