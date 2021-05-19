#pragma once
#include <ctime>
#include <string>
#include "cVehiculo.h"
#include "Cliente.h"
using namespace std;

class Alquiler
{
	friend class cListaAlquileres;
private:
	unsigned int cant_elementos_seguridad;
	tm fecha_inicio;
	tm fin_reserva;
	string tipo_vehiculo;
	string Vehiculo;
	string cliente;
	cVehiculo* vehiculo;
	unsigned int monto_total;
public:
	Alquiler(unsigned int cant_elementos_seguridad, tm fecha_inicio, tm fin_reserva, cVehiculo* vehiculo, Cliente* cliente);
	~Alquiler();
};

