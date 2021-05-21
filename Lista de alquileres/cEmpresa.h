#pragma once
#include "cListaAlquileres.h"
#include "Cliente.h"
#include "cVehiculo.h"
class cEmpresa
{
	cLista<Cliente>* ListaClientes;
	cLista<cVehiculo>* ListaVehiculos; //las funciones de agregar y/o retirar vehiculos ya estan incluidas en la lista template
	cListaAlquileres* Lista_Alquileres;
public:
	cEmpresa(cLista<Cliente>* lista_clientes, cLista<cVehiculo>* lista_Vehiculos, cListaAlquileres* lista_alquileres);
	~cEmpresa();
	void AdquirirVehiculo(cVehiculo* nuevo);
	void RetirarVehiculo(cVehiculo* retirado);
	void RealizarMantenimiento(cVehiculo* vehiculo);
};

