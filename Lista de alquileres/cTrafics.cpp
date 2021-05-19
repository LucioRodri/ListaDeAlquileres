#include "cTrafics.h"

cTrafics::cTrafics(const unsigned int asientos, const unsigned int sillas, unsigned int capacidad, string color, tm* fecha, unsigned int chasis, string patente, unsigned int poliza, unsigned int base, unsigned int dias) :cant_asientos(asientos), cant_sillas(sillas), cVehiculo(capacidad, color, fecha, chasis, patente, poliza, base, dias)
{
	tipo_vehiculo = "\nTrafic";
}

cTrafics::~cTrafics()
{
}

cTrafics::cTrafics(cTrafics* copia) : cVehiculo(copia), cant_asientos(copia->cant_asientos), cant_sillas(copia->cant_sillas)
{
	tipo_vehiculo = "\nTrafic";
}

float cTrafics::calcular_tarifa()
{
    return precio_dia * cant_dias + cant_sillas * precio_silla_ninios + cant_asientos * precio_asiento_rebatible + precio_base;
}

void cTrafics::pasos_mantenimiento()
{
	time_t now = time(0);
	tm* time = localtime(&now);
	fecha_ultimo_mantenimiento->tm_year = time->tm_year;
	fecha_ultimo_mantenimiento->tm_mon = time->tm_mon;
	fecha_ultimo_mantenimiento->tm_mday = time->tm_mday;
	cout << "\nPrimero, verificar que los airbags esten recargados\nSegundo, cambiar los frenos\nTercero, verificar el funcionamiento de los cinturones de seguridad\nCuarto, cambiar aceite\nQuinto, revisar el quilometraje\nSexto, chequear suciedad en la parte trasera" << endl;
}
string cTrafics::to_string()
{
	return "\nCantidad de asientos: "+ std::to_string(cant_asientos)+ "\nPrecio x dia: "+ std::to_string(precio_dia)+ "\nCantidad de sillas para ninos: "+
	std::to_string(cant_sillas)+ "\nPrecio x silla para nino: "+ std::to_string(precio_silla_ninios)+ "\nPrecio x asiento rebatible: "+ 
	std::to_string(precio_asiento_rebatible)+ cVehiculo::to_string();
}
unsigned int cTrafics::cant_elementos_seguridad()
{
	return cant_sillas + cant_asientos + 8; //suponemos 4 cinturones y 2 airbags para la trafic
}
void cTrafics::Imprimir()
{
	cout << to_string() << endl;
}