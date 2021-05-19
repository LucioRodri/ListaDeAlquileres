#pragma once
#include <string>
#include <iostream>
#include <algorithm>


using namespace std;

#define TMAX 150
template <class T1, class T2, class T3> 
class cLista
{
	friend class cEmpresa;
protected:
	T1** lista;
	unsigned int ca, t;
public:
	cLista(unsigned int T = TMAX);
	~cLista(void);
	void Insertar(T1* P);
	T1* Quitar(T2 clave);
	T1* Quitar(T3 clave);
	void Eliminar(T2 clave);
	void Eliminar(T3 clave);
	T1* Buscar(T2 Clave);
	T1* Buscar(T3 Clave);
	unsigned int BuscarAtPos(T2 Clave);
	unsigned int BuscarAtPos(T3 Clave);

	T1* QuitarPos(unsigned int pos);
	void EliminarenPos(unsigned int pos);
	void Switch(unsigned int pos1, unsigned int pos2);
	int getCA() const { return ca; };
	void operator+(T1* p);


	T1* operator[](unsigned int pos)
	{
		if (pos < ca)
			return lista[pos];
		else throw new exception("No se encontro el elemento pedido");
	};
};
