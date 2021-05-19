#include "cListaAlquileres.h"

/*void cListaAlquileres::listar_por_tipo()
{
	Alquiler** aux;
	int cont = 0;
	for (int i = 0; i < ca - 1; i++)
	{
		if (lista[i]->tipo_vehiculo == "Auto")
		{
			aux[cont] = lista[i];
			cont++;
		}
	}
	for (int i = 0; i < ca - 1; i++)
	{
		if (lista[i]->tipo_vehiculo == "Camioneta")
		{
			aux[cont] = lista[i];
			cont++;
		}
	}
	for (int i = 0; i < ca - 1; i++)
	{
		if (lista[i]->tipo_vehiculo == "Moto")
		{
			aux[cont] = lista[i];
			cont++;
		}
	}
	for (int i = 0; i < ca - 1; i++)
	{
		if (lista[i]->tipo_vehiculo == "Trafic")
		{
			aux[cont] = lista[i];
			cont++;
		}
	}
	delete lista;
	lista = aux;
}*/
void cListaAlquileres::listar_por_tipo()
{
	Alquiler** aux;
	int cont = 0;
	cMotocicleta* pMoto;
	cTrafics* pTrafic;
	cAutomoviles* pAuto;
	cCamioneta* pCamioneta;
	for (int i = 0; i < ca - 1; i++)
	{
		pAuto = dynamic_cast<cAutomoviles*>(lista[i]->vehiculo);
		if (pAuto!=NULL)
		{
			aux[cont] = lista[i];
			cont++;
		}
	}
	for (int i = 0; i < ca - 1; i++)
	{
		pCamioneta = dynamic_cast<cCamioneta*>(lista[i]->vehiculo);
		if (pCamioneta != NULL)
		{
			aux[cont] = lista[i];
			cont++;
		}
	}
	for (int i = 0; i < ca - 1; i++)
	{
		pMoto = dynamic_cast<cMotocicleta*>(lista[i]->vehiculo);
		if (pMoto!=NULL)
		{
			aux[cont] = lista[i];
			cont++;
		}
	}
	for (int i = 0; i < ca - 1; i++)
	{
		pTrafic = dynamic_cast<cTrafics*>(lista[i]->vehiculo);
		if (pCamioneta != NULL)
		{
			aux[cont] = lista[i];
			cont++;
		}
	}
	delete lista;
	lista = aux;
}

unsigned int cListaAlquileres::ganancia_total()
{
	int i, cont=0;
	for(i=0;i<ca;i++)
	{
		cont+=lista[i]->monto_total;
	}
	return cont;
}
