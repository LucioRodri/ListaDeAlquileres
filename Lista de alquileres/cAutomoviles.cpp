#include "cAutomoviles.h"
cAutomoviles::cAutomoviles(unsigned int cant_sillas, unsigned int capacidad_pasajeros, string color, tm* fecha, unsigned int chasis, string patente,
    unsigned int poliza, unsigned int base, unsigned int dias):cant_sillas(cant_sillas), cVehiculo(capacidad_pasajeros, color, 
    fecha, chasis, patente, poliza, base, dias)
{
	tipo_vehiculo = "\nAuto";
}

cAutomoviles::cAutomoviles(cAutomoviles* copia) :cant_sillas(copia->cant_sillas), cVehiculo(copia)
{
	tipo_vehiculo = "\nAuto";
}
cAutomoviles::~cAutomoviles()
{
}
float cAutomoviles::Calcular_tarifa()
{
    return (cant_sillas * precio_sillas + precio_base + precio_dia*cant_dias);
}
void cAutomoviles::pasos_mantenimiento()
{
	time_t now = time(0);
	tm* time = localtime(&now);
	fecha_ultimo_mantenimiento->tm_year = time->tm_year + 1900;
	fecha_ultimo_mantenimiento->tm_mon = time->tm_mon + 1;
	fecha_ultimo_mantenimiento->tm_mday = time->tm_mday;
	cout << "\nPrimero, verificar que los airbags esten recargados\nSegundo, cambiar los frenos\nTercero, verificar el funcionamiento de los cinturones de seguridad\nCuarto, cambiar aceite\nQuinto, revisar el quilometraje\nSexto, chequear el motor" << endl;
}
unsigned int cAutomoviles::cant_elementos_seguridad()
{
	return cant_sillas + 7; //suponemos 5 cinturones y 2 airbags
}

string cAutomoviles::to_string()
{
	return cVehiculo::to_string() + "\nSillas: " + std::to_string(cant_sillas) + "\nPrecio dia: " + std::to_string(precio_dia);
}

void cAutomoviles::Imprimir()
{
	cout << to_string() << endl;
}
