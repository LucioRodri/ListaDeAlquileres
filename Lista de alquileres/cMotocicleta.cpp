#include "cMotocicleta.h"

cMotocicleta::cMotocicleta(unsigned int cascos, unsigned int precio_dia, unsigned int capacidad_pasajeros,
string color,  tm* fecha, unsigned int chasis, string patente, unsigned int poliza, unsigned int base, unsigned int dias): cascos(cascos), 
cVehiculo(capacidad_pasajeros, color, fecha, chasis, patente, poliza, base, dias)
{
	tipo_vehiculo = "\nMoto";
}

cMotocicleta::cMotocicleta(cMotocicleta* copia): cascos(copia->cascos), cVehiculo(copia)
{	
	tipo_vehiculo = "\nMoto";
}

cMotocicleta::~cMotocicleta()
{
}

float cMotocicleta::Calcular_tarifa()
{
	return precio_base+precio_cascos*cascos + precio_dia*cant_dias;
}

void cMotocicleta::pasos_mantenimiento()
{
	time_t now = time(0);
	tm* time = localtime(&now);
	fecha_ultimo_mantenimiento->tm_year = time->tm_year + 1900;
	fecha_ultimo_mantenimiento->tm_mon = time->tm_mon + 1;
	fecha_ultimo_mantenimiento->tm_mday = time->tm_mday;
	cout << "\nPrimero, verificar que el airbag este recargado\nSegundo, cambiar los frenos\nTercero, cambiar aceite\nCuarto, revisar el quilometraje\nCuarto, revisar cascos" << endl;
}
unsigned int cMotocicleta::cant_elementos_seguridad()
{
	return 0;
}
string cMotocicleta::to_string()
{
	return "\nPasajeros: " + std::to_string(capacidad_pasajeros) + "\nColor: " + color + 
		"\nUltimo service: " + ConverttmString(*fecha_ultimo_mantenimiento) +
		"\nChasis: " + std::to_string(numero_chasis) + "\nPatente: " + numero_patente + 
		"\nPoliza: " + std::to_string(numero_poliza) + "\nPrecio base: " + std::to_string(precio_base) + 
		"\nDias: " + std::to_string(cant_dias) + "\nPrecio x dia: " + std::to_string(precio_dia) + 
		"\ncantidad de cascos: " + std::to_string(cascos) + "\nPasajeros: " + std::to_string(capacidad_pasajeros) + "\nColor: " + color + 
		"\nUltimo service: " + ConverttmString(*fecha_ultimo_mantenimiento) + "\nChasis: " + std::to_string(numero_chasis) + "\nPatente: " +
		numero_patente + "\nPoliza: " + std::to_string(numero_poliza) + "\nPrecio base: " + std::to_string(precio_base) + "\nDias: " +
		std::to_string(cant_dias);
};

void cMotocicleta::Imprimir()
{
	cout << to_string() << endl;
}
