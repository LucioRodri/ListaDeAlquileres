#pragma once
#include "cLista.h"
#include "Alquiler.h"
#include "cVehiculo.h"
#include"cAutomoviles.h"
#include"cCamioneta.h"
#include"cMotocicleta.h"
#include"cTrafics.h"
class cListaAlquileres :
    public cLista<Alquiler,cVehiculo,string>
{
public:
    void listar_por_tipo();
    unsigned int ganancia_total();
};

