#include "cVehiculo.h"

cVehiculo::cVehiculo(unsigned int capacidad, string color, tm* fecha, unsigned int chasis, string patente, unsigned int poliza, unsigned int base, unsigned int dias)
{
	this->capacidad_pasajeros = capacidad;
	this->color = color;
	this->fecha_ultimo_mantenimiento = fecha;
	this->numero_chasis = chasis;
	this->numero_patente = patente;
	this->numero_poliza = poliza;
	this->precio_base = base;
	this->cant_dias = dias;
}//Aca se produce un punto de interrupcion

cVehiculo::cVehiculo(cVehiculo* copia)
{
	this->capacidad_pasajeros = copia->capacidad_pasajeros;
	this->color = copia->color;
	this->fecha_ultimo_mantenimiento = copia->fecha_ultimo_mantenimiento;
	this->numero_chasis = copia->numero_chasis;
	this->numero_patente = copia->numero_patente;
	this->numero_poliza = copia->numero_poliza;
	this->precio_base = copia->precio_base;
	this->cant_dias = copia->cant_dias;
}

cVehiculo::~cVehiculo()
{
}

float cVehiculo::Calcular_tarifa()
{
	return 0.0f;
}

void cVehiculo::pasos_mantenimiento()
{
}

unsigned int cVehiculo::cant_elementos_seguridad()
{
	return 0;
}

string cVehiculo::to_string()
{
	return "";
}

void cVehiculo::Imprimir()
{
	cout << to_string() << endl;
}
