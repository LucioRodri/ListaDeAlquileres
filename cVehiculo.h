#pragma once
#include <string>
#include <iostream>
#include <ctime>
using namespace std;
class cVehiculo
{
protected:
	unsigned int capacidad_pasajeros;
	string color;
	tm fecha_ultimo_mantenimiento;
	unsigned int numero_chasis;
	string numero_patente; //cambiar a string tambien en uml
	unsigned int numero_poliza;
	unsigned int precio_base;
public:
	cVehiculo(unsigned int capacidad = 1, string color = "negro", tm fecha = { 0 }, unsigned int chasis = 0, string patente = "", unsigned int poliza = 0, unsigned int base = 100);
	cVehiculo(cVehiculo* copia);
	~cVehiculo();
	virtual float calcular_tarifa();
	virtual void pasos_mantenimiento();
};