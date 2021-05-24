#include "Alquiler.h"

Alquiler::Alquiler(unsigned int cant_elementos_seguridad, tm* fecha_inicio, tm* fin_reserva, cVehiculo* vehiculo, Cliente* cliente)
{
	this->cant_elementos_seguridad=cant_elementos_seguridad;
	this->fecha_inicio = fecha_inicio;
	this->fin_reserva=fin_reserva;
	this->monto_total = vehiculo->Calcular_tarifa();
	this->Vehiculo = vehiculo->to_string();
	this->cliente = cliente->to_string();
	this->tipo_vehiculo = vehiculo->get_tipo();//Aca lanza un punto de interrupcion
	this->vehiculo = vehiculo;
}

Alquiler::~Alquiler()
{
}

string Alquiler::to_string()
{
	return "\nFecha de inicio de reserva: "+ ConverttmString(*fecha_inicio)+ "\nFecha de finalizacion de reserva: "+ 
		ConverttmString(*fin_reserva)+ "\nCantidad de elementos de seguridad: "+ std::to_string(cant_elementos_seguridad)+ 
		"\nTipo de vehiculo: "+ tipo_vehiculo + cliente+ Vehiculo+ "\nMonto total: "+ std::to_string(monto_total);
}
