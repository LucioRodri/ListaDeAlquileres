#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string>
#include <iostream>
#include <ctime>
#include "Funciones.h"
using namespace std;
class cVehiculo
{
protected:
	unsigned int capacidad_pasajeros;
	string color;
	tm* fecha_ultimo_mantenimiento;
	unsigned int numero_chasis;
	string numero_patente; //cambiar a string tambien en uml
	unsigned int numero_poliza;
	unsigned int precio_base;
	unsigned int cant_dias;
	string tipo_vehiculo;
public:
	cVehiculo(unsigned int capacidad = 1, string color = "negro", tm* fecha = { 0 }, unsigned int chasis = 0, string patente = "", unsigned int poliza = 0, unsigned int base = 100, unsigned int dias = 10);
	cVehiculo(cVehiculo* copia);
	~cVehiculo();
	virtual float Calcular_tarifa();
	virtual void pasos_mantenimiento();
	virtual unsigned int cant_elementos_seguridad();
	virtual string to_string();
	virtual void Imprimir();
	string get_tipo() { return tipo_vehiculo; };
	virtual string get_patente() { return numero_patente; };
	//ostream& operator<<(ostream& out, const cVehiculo& M) { out << M.to_string() << endl; return out; }
};

