#define _CRT_SECURE_NO_WARNINGS
#include "cEmpresa.h"
#include "cLista.h"
#include "cVehiculo.h"
#include "Alquiler.h"
#include <string>
#include <iostream>

using namespace std;
int main()
{
	time_t now = time(0);
	tm* time = localtime(&now);
	time->tm_year += 1900;
	time->tm_mon += 1;
	int total;
	//empezamos probando las funciones de cAutomoviles
	cAutomoviles* pAuto= new cAutomoviles(3, 4, "violeta", time, 123, "abc-123", 456, 20, 4);
	cVehiculo* pVehiculo=pAuto;
	pAuto->pasos_mantenimiento(); //imprime mes y anio mal
	total = pAuto->Calcular_tarifa();
	cout<<total<<endl;
	total = pAuto->cant_elementos_seguridad();
	cout<<total<<endl;
	pVehiculo->Imprimir();

	//funciones de motocicleta
	cMotocicleta* pMoto = new cMotocicleta(2, 50, 2, "rojo", time, 1542, "arf-321", 43162, 100, 5);
	total = pMoto->Calcular_tarifa();
	pMoto->pasos_mantenimiento();
	cout << total << endl;
	total = pMoto->cant_elementos_seguridad();
	cout << total << endl;
	pMoto->Imprimir();

	//funciones de camioneta
	cCamioneta* pCamioneta = new cCamioneta(true, 2, 6, "gris", time, 5243, "trf-432", 12342, 1000, 4);
	total = pCamioneta->Calcular_tarifa();
	pCamioneta->pasos_mantenimiento();
	cout << total << endl;
	total = pCamioneta->cant_elementos_seguridad();
	cout << total << endl;

	//funciones de trafics
	cTrafics* pTrafics = new cTrafics(1, 6, 12, "negro", time, 431, "acd-350", 23478, 60, 5);
	total = pTrafics->Calcular_tarifa();
	pTrafics->pasos_mantenimiento();
	cout << total << endl;
	total = pTrafics->cant_elementos_seguridad();
	cout << total << endl;
	pTrafics->Imprimir();

	//creo 3 alquileres para probar en la lista de alquileres
	unsigned int pos;
	string err;
	Cliente* cliente1 = new Cliente("Pedro", "2312312");
	cListaAlquileres* listaAlquileres = new cListaAlquileres();
	Alquiler* ptr_alquiler = new Alquiler(3, time, time, pCamioneta, cliente1);
	try {
		listaAlquileres->Insertar(new Alquiler(6, time, time, pAuto, cliente1));
	}
	catch(exception* error){
		err = error->what();
		delete error;
		cout << err << endl;
	}
	try {
		listaAlquileres->Insertar(ptr_alquiler);
	}
	catch(exception* error){
		err = error->what();
		delete error;
		cout << error << endl;
	}
	try {
		listaAlquileres->Insertar(new Alquiler(2, time, time, pMoto, cliente1));
	}
	catch(exception* error){
		err = error->what();
		delete error;
		cout << err << endl;
	}
	try {
		pos = listaAlquileres->BuscarAtPos(ptr_alquiler);
	}
	catch (exception* error)
	{
		err = error->what();
		delete error;
		cout << error << endl;
	}
	try {
		listaAlquileres->Eliminar(ptr_alquiler);
	}
	catch (exception* error) {
		err = error->what();
		delete error;
		cout << err << endl;
	}
	listaAlquileres->listar_por_tipo();

	//Probamos que maneje bien las excepciones de lista
	//redujimos el tamanio maximo de la lista de 150 a 5 para testear
	try {
		listaAlquileres->Insertar(new Alquiler(3, time, time, pCamioneta, cliente1));
		listaAlquileres->Insertar(new Alquiler(3, time, time, pCamioneta, cliente1));//tira exepcion al encontrar el mismo
		listaAlquileres->Insertar(new Alquiler(3, time, time, pAuto, cliente1));
		listaAlquileres->Insertar(new Alquiler(3, time, time, pTrafics, cliente1));
		pTrafics = new cTrafics(3, 8, 10, "purpura", time, 252, "tgf-456", 9821, 1000, 5);
		listaAlquileres->Insertar(new Alquiler(3, time, time, pTrafics , cliente1));//tira excepcion al agregar uno mas de la capacidad maxima de la lista
	}
	catch (exception* error) {
		err = error->what();
		delete error;
		cout << err << endl;
	}
	return 0;
}