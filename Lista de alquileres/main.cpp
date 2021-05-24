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
	string err;
	cLista<cVehiculo>* ListaVehiculo = new cLista<cVehiculo>(false);
	cLista<Cliente>* ListaCliente = new cLista<Cliente>();
	//empezamos probando las funciones de cAutomoviles
	cAutomoviles* pAuto= new cAutomoviles(3, 4, "violeta", time, 123, "abc-123", 456, 20, 4);
	try {
		ListaCliente->Insertar(new Cliente("Pedro Picapiedra", "12345678"));
	}
	catch (exception* error) {
		err = error->what();
		delete error;
		cout << err << endl;
	}
	try {
		ListaVehiculo->Insertar(pAuto);
	}
	catch (exception* error) {
		err = error->what();
		delete error;
		cout << err << endl;
	}
	cVehiculo* pVehiculo=pAuto;
	pAuto->pasos_mantenimiento(); //imprime mes y anio mal
	total = pAuto->Calcular_tarifa();
	cout<<total<<endl;
	total = pAuto->cant_elementos_seguridad();
	cout<<total<<endl;
	pVehiculo->Imprimir();

	//funciones de motocicleta
	cMotocicleta* pMoto = new cMotocicleta(2, 50, 2, "rojo", time, 1542, "arf-321", 43162, 100, 5);
	try {
		ListaVehiculo->Insertar(pMoto);
	}
	catch (exception* error) {
		err = error->what();
		delete error;
		cout << err << endl;
	}
	total = pMoto->Calcular_tarifa();
	pMoto->pasos_mantenimiento();
	cout << total << endl;
	total = pMoto->cant_elementos_seguridad();
	cout << total << endl;
	pMoto->Imprimir();

	//funciones de camioneta
	cCamioneta* pCamioneta = new cCamioneta(true, 2, 6, "gris", time, 5243, "trf-432", 12342, 1000, 4);
	try {
		ListaVehiculo->Insertar(pCamioneta);
	}
	catch (exception* error) {
		err = error->what();
		delete error;
		cout << err << endl;
	}
	total = pCamioneta->Calcular_tarifa();
	pCamioneta->pasos_mantenimiento();
	cout << total << endl;
	total = pCamioneta->cant_elementos_seguridad();
	cout << total << endl;

	//funciones de trafics
	cTrafics* pTrafics = new cTrafics(1, 6, 12, "negro", time, 431, "acd-350", 23478, 60, 5);
	try {
		ListaVehiculo->Insertar(pTrafics);
	}
	catch (exception* error) {
		err = error->what();
		delete error;
		cout << err << endl;
	}
	total = pTrafics->Calcular_tarifa();
	pTrafics->pasos_mantenimiento();
	cout << total << endl;
	total = pTrafics->cant_elementos_seguridad();
	cout << total << endl;
	pTrafics->Imprimir();

	//creo 3 alquileres para probar en la lista de alquileres
	unsigned int pos;
	Cliente* cliente1 = new Cliente("Pedro", "2312312");
	try {
		ListaCliente->Insertar(cliente1);
	}
	catch (exception* error) {
		err = error->what();
		delete error;
		cout << err << endl;
	}
	cListaAlquileres* listaAlquileres = new cListaAlquileres();
	Alquiler* ptr_alquiler = new Alquiler(3, time, time, pAuto, cliente1);
	try {
		listaAlquileres->Insertar(ptr_alquiler);
	}
	catch(exception* error){
		err = error->what();
		delete error;
		cout << err << endl;
	}
	ptr_alquiler = new Alquiler(3, time, time, pCamioneta, cliente1);
	try {
		listaAlquileres->Insertar(ptr_alquiler);
	}
	catch(exception* error){
		err = error->what();
		delete error;
		cout << error << endl;
	}
	ptr_alquiler = new Alquiler(2, time, time, pMoto, cliente1);
	try {
		listaAlquileres->Insertar(ptr_alquiler);
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
	ptr_alquiler = new Alquiler(3, time, time, pCamioneta, cliente1);
	try {
		*listaAlquileres + ptr_alquiler;
		//listaAlquileres->operator+(ptr_alquiler);
	}
	catch (exception* error) {
		err = error->what();
		delete error;
		cout << err << endl;
	}
	try {
		*listaAlquileres + ptr_alquiler;
		//listaAlquileres->operator+(ptr_alquiler);//tira exepcion al encontrar el mismo
	}
	catch (exception* error) {
		err = error->what();
		delete error;
		cout << err << endl;
	}
	ptr_alquiler = new Alquiler(3, time, time, pAuto, cliente1);
	try {
		*listaAlquileres+ptr_alquiler;//no deberian tirar excepcion
	}
	catch (exception* error) {
		err = error->what();
		delete error;
		cout << err << endl;
	}
	ptr_alquiler = new Alquiler(3, time, time, pTrafics, cliente1);
	try {
		*listaAlquileres+ptr_alquiler;
	}
	catch (exception* error) {
		err = error->what();
		delete error;
		cout << err << endl;
	}
	pTrafics = new cTrafics(3, 8, 10, "purpura", time, 252, "tgf-456", 9821, 1000, 5);
	ptr_alquiler = new Alquiler(3, time, time, pTrafics, cliente1);
	try{
		*listaAlquileres+ptr_alquiler;//tira excepcion al agregar uno mas de la capacidad maxima de la lista
	}
	catch (exception* error) {
		err = error->what();
		delete error;
		cout << err << endl;
	}
	delete ptr_alquiler;
	ptr_alquiler = new Alquiler(3, time, time, pTrafics, cliente1);
	try {
		listaAlquileres->Eliminar(ptr_alquiler);//tira exepcion al encontrar el mismo
	}
	catch (exception* error) {
		err = error->what();
		delete error;
		cout << err << endl;
	}
	//probamos alguna funcion de empresa, ya que son iguales a las de listas template, probadas anteriormente
	
	cEmpresa* Empresa = new cEmpresa(ListaCliente, ListaVehiculo, listaAlquileres);
	try {
		Empresa->RetirarVehiculo(pTrafics);
	}
	catch (exception* error) {
		err = error->what();
		delete error;
		cout << err << endl;
	}
	//cout << listaAlquileres->to_string() << endl;
	cout << *listaAlquileres << endl;
	cout << *ListaCliente << endl;
	cout << *ListaVehiculo << endl;
	return 0;
}