#include "cEmpresa.h"

void cEmpresa::AdquirirVehiculo(cVehiculo* nuevo)
{
	ListaVehiculos->operator+(nuevo);
}

void cEmpresa::RetirarVehiculo(cVehiculo* retirado)
{
	ListaVehiculos->Quitar(retirado->get_patente());
}

void cEmpresa::RealizarMantenimiento(cVehiculo* vehiculo)
{
	int pos;
	pos = ListaVehiculos->BuscarAtPos(vehiculo->get_patente());
	ListaVehiculos->lista[pos]->pasos_mantenimiento();
}
