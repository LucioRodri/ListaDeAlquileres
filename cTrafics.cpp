#include "cTrafics.h"

cTrafics::cTrafics(const unsigned int asientos, const unsigned int sillas) :cant_asientos(asientos), cant_sillas(sillas)
{
}
const unsigned int cTrafics::precio_asiento_rebatible = 10;
const unsigned int cTrafics::precio_dia = 15;
const unsigned int precio_silla_ninios = 20;
cTrafics::~cTrafics()
{
}

float cTrafics::calcular_tarifa()
{
    return 0.0f;
}

void cTrafics::pasos_mantenimiento()
{
}