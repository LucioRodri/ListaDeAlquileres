#pragma once
#include "cLista.h"
#include "Alquiler.h"
#include "cVehiculo.h"
#include"cAutomoviles.h"
#include"cCamioneta.h"
#include"cMotocicleta.h"
#include"cTrafics.h"

class cEmpresa;
class cListaAlquileres :
    public cLista<Alquiler>
{
public:
    void listar_por_tipo();
    unsigned int ganancia_total();
};

