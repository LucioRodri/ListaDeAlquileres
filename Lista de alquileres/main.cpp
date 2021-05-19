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
	int total;
	//empezamos probando las funciones de cAutomoviles
	cAutomoviles* pAuto= new cAutomoviles(3, 4, "violeta", time, 123, "abc-123", 456, 20, 4);
	cVehiculo* pVehiculo=pAuto;
	pAuto->pasos_mantenimiento();
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

	return 0;
}