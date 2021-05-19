#pragma once
#include "cLista.h"
#include "cListaAlquileres.h"
#include "Cliente.h"
#include "cVehiculo.h"

class cEmpresa
{
	cLista<Cliente,string,string>* ListaClientes;
	cLista<cVehiculo,string,unsigned int>* ListaVehiculos; //las funciones de agregar y/o retirar vehiculos ya estan incluidas en la lista template
	cListaAlquileres* Lista_Alquileres;
public:
	void AdquirirVehiculo(cVehiculo* nuevo);
	void RetirarVehiculo(cVehiculo* retirado);
	void RealizarMantenimiento(cVehiculo* vehiculo);
};

