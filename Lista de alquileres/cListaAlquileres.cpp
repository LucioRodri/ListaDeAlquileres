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
	Alquiler** aux=new Alquiler*[ca];
	for (int i = 0; i < ca; i++)
	{
		aux[i] = NULL;
	}
	int cont = 0;
	cMotocicleta* pMoto = NULL;
	cTrafics* pTrafic = NULL;
	cAutomoviles* pAuto = NULL;
	cCamioneta* pCamioneta = NULL;
	for (int i = 0; i < ca; i++)
	{
		pAuto = dynamic_cast<cAutomoviles*>(lista[i]->vehiculo);
		if (pAuto!=NULL)
		{
			aux[cont] = lista[i];
			cont++;
		}
	}
	for (int i = 0; i < ca; i++)
	{
		pCamioneta = dynamic_cast<cCamioneta*>(lista[i]->vehiculo);
		if (pCamioneta != NULL)
		{
			aux[cont] = lista[i];
			cont++;
		}
	}
	for (int i = 0; i < ca; i++)
	{
		pMoto = dynamic_cast<cMotocicleta*>(lista[i]->vehiculo);
		if (pMoto!=NULL)
		{
			aux[cont] = lista[i];
			cont++;
		}
	}
	for (int i = 0; i < ca; i++)
	{
		pTrafic = dynamic_cast<cTrafics*>(lista[i]->vehiculo);
		if (pTrafic != NULL)
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
