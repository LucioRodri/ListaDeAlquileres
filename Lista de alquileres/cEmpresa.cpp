#include "cEmpresa.h"

cEmpresa::cEmpresa(cLista<Cliente>* lista_clientes, cLista<cVehiculo>* lista_Vehiculos,  cListaAlquileres* lista_alquileres)
{
	ListaClientes = lista_clientes;
	ListaVehiculos = lista_Vehiculos;
	Lista_Alquileres = lista_alquileres;
}

cEmpresa::~cEmpresa()
{
	delete ListaClientes;
	delete ListaVehiculos;
	delete Lista_Alquileres;
}

void cEmpresa::AdquirirVehiculo(cVehiculo* nuevo)
{
	try {
		ListaVehiculos->operator+(nuevo);
	}
	catch (exception* error)
	{
		throw error;
	}
}

void cEmpresa::RetirarVehiculo(cVehiculo* retirado)
{
	try {
		ListaVehiculos->Quitar(retirado);
	}
	catch (exception* error)
	{
		throw error;
	}
}

void cEmpresa::RealizarMantenimiento(cVehiculo* vehiculo)
{
	int pos;
	try {
		pos = ListaVehiculos->BuscarAtPos(vehiculo);
	}
	catch (exception* error)
	{
		throw error;
	}
	ListaVehiculos->lista[pos]->pasos_mantenimiento();
}
