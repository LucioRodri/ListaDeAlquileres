#include "Alquiler.h"

Alquiler::Alquiler(unsigned int cant_elementos_seguridad, tm fecha_inicio, tm fin_reserva, cVehiculo* vehiculo, Cliente* cliente)
{
	this->cant_elementos_seguridad=cant_elementos_seguridad;
	this->fecha_inicio = fecha_inicio;
	this->fin_reserva=fin_reserva;
	this->monto_total = vehiculo->Calcular_tarifa();
	this->Vehiculo = vehiculo->to_string();
	this->cliente = cliente->to_string();
	this->tipo_vehiculo = vehiculo->get_tipo();
	this->vehiculo = vehiculo;
}

Alquiler::~Alquiler()
{
}
