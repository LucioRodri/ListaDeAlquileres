#pragma once
#include <ctime>

class Alquiler
{
private:
	unsigned int cant_elementos_seguridad;
	tm fecha_inicio;
	tm fin_reserva;
	unsigned int monto_total;
public:
	Alquiler(unsigned int cant_elementos_seguridad, tm fecha_inicio, tm fin_reserva, unsigned int monto_total);
	~Alquiler();
};
