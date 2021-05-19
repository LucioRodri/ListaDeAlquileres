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
}

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
	return "\nPasajeros: " + std::to_string(capacidad_pasajeros) + "\nColor: " + color + "\nUltimo service: " + ConverttmString(*fecha_ultimo_mantenimiento) + "\nChasis: " + std::to_string(numero_chasis) + "\nPatente: " + numero_patente + "\nPoliza: " + std::to_string(numero_poliza) + "\nPrecio base: " + std::to_string(precio_base) + "\nDias: " + std::to_string(cant_dias);
}

void cVehiculo::Imprimir()
{
	cout << to_string() << endl;
}
