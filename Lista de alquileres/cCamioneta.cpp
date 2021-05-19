#include "cCamioneta.h"

cCamioneta::cCamioneta(bool portaequipaje, unsigned int cant_silla_ninios, unsigned int capacidad, string color, tm* fecha, unsigned int chasis, string patente, unsigned int poliza, unsigned int base, unsigned int dias):cant_silla_ninios(cant_silla_ninios),cVehiculo(capacidad,color,fecha,chasis,patente,poliza,base,dias)
{
	this->portequipaje = portaequipaje;
	tipo_vehiculo = "\nCamioneta";
}
const unsigned int cCamioneta::precio_portaequipaje = 50;
const unsigned int cCamioneta::precio_sillas = 25;
unsigned int cCamioneta::precio_dia = 45;

cCamioneta::cCamioneta(cCamioneta* copia):cant_silla_ninios(copia->cant_silla_ninios), cVehiculo(copia)
{
	this->portequipaje = copia->portequipaje;
	tipo_vehiculo = "\nCamioneta";
}

cCamioneta::~cCamioneta()
{
}

float cCamioneta::Calcular_tarifa()
{
	if (portequipaje == true)
		return precio_dia * cant_dias + cant_silla_ninios * precio_base + precio_base + precio_portaequipaje;
	else
		return precio_dia * cant_dias + cant_silla_ninios * precio_sillas + precio_base;
}

void cCamioneta::PasosMantenimiento()
{
	time_t now = time(0);
	tm* time = localtime(&now);
	fecha_ultimo_mantenimiento->tm_year = time->tm_year;
	fecha_ultimo_mantenimiento->tm_mon = time->tm_mon;
	fecha_ultimo_mantenimiento->tm_mday = time->tm_mday;
	cout << "\nPrimero, verificar que los airbags esten recargados\nSegundo, cambiar los frenos\nTercero, verificar el funcionamiento de los cinturones de seguridad\nCuarto, cambiar aceite\nQuinto, revisar el quilometraje" << endl;
}

string cCamioneta::to_string()
{
	string equipaje;
	if (portequipaje == true)
		equipaje = "\nPortaequipaje: Si";
	else
		equipaje = "\nPortaequipaje: No";
	return cVehiculo::to_string()+ equipaje + "\nCantidad sillas ninios: " + std::to_string(cant_silla_ninios) + "\nDia: " + std::to_string(precio_dia);
}
unsigned int cCamioneta::cant_elementos_seguridad()
{
	return cant_silla_ninios + 7;//Asumo 5 cinturones de seguridad + 2 airbags
}