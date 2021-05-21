#pragma once
#include <string>
#include <iostream>

using namespace std;	//ATENCION: DEBEN AGREGAR LAS EXCEPCIONES CORRESPONDIENTES PARA EVITAR ERRORES CUANDO USEN LA LISTA

#define TMAX 150
template <class T1> //Indico que voy a hacer uso de Template y la clase T1 sera la generica
class cLista
{
protected:
	T1** lista;
	unsigned int ca, t;
	friend class cEmpresa;

public:
	cLista(unsigned int T = TMAX);
	~cLista(void);


	// Metodos Tipicos

	void Insertar(T1* P);			//Como ven, trabajamos constantemente con la clase "T1" que luego le asignaremos
	T1* Quitar(T1* clave);		//la clase o tipo que queramos para la lista (en el main, al crear una lista)
	void Eliminar(T1* clave);
	void EliminarenPos(unsigned int);
	T1* Buscar(T1* Clave);
	unsigned int BuscarAtPos(T1* Clave);

	void operator+(T1* p);

	T1* operator[](unsigned int pos)
	{
		if (pos < ca)
			return lista[pos];
		return NULL;
	}

	T1* operator[](string clave)
	{
		return Buscar(clave);
	}


	void Listar();

};									//Los metodos deben estar definidos en el .h, para evitar otros que arreglos que habria que hacer

template <class T1>					//Es importante, antes de cada metodo, colocar esta sentencia
cLista<T1>::cLista(unsigned int T)	//Y tambien es importante colocar antes del operador de ambito la clase generica <T1>
{
	t = T;
	ca = 0;
	lista = new T1 * [T];

	for (int i = 0; i < T; i++)
	{
		lista[i] = NULL;
	}


}

template <class T1>
cLista<T1>::~cLista(void)
{
	if (lista != NULL) {

		for (int i = 0; i < ca; i++)
		{
			if (lista[i] != NULL)
				delete lista[i];
		}
		delete[]lista;

	}


}

// Metodos Tipicos
template <class T1>
void cLista<T1>::Insertar(T1* P)
{

	if (ca < t)
		lista[ca++] = P;


}
template <class T1>
void cLista<T1>::operator+(T1* P)
{

	if (ca < t)
		lista[ca++] = P;


}

template <class T1>
T1* cLista<T1>::Quitar(T1* clave)
{
	unsigned int i = BuscarAtPos(clave);

	if (i >= ca)return NULL;

	T1* aux = lista[i];

	ca--;
	for (unsigned int j = i; j < ca; j++)
	{
		lista[j] = lista[j + 1];

	}

	lista[ca] = NULL;
	return aux;


}
template <class T1>
void cLista<T1>::Eliminar(T1* clave)
{

	T1* aux = Quitar(clave);

	if (aux != NULL)
		delete aux;


}
template <class T1>
void cLista<T1>::EliminarenPos(unsigned int pos)
{
	if (pos >= ca)return;
	delete lista[pos];
	ca--;
	for (int j = pos; j < ca; j++)
	{
		lista[j] = lista[j + 1];

	}

	lista[ca] = NULL;
	return;
}
template <class T1>
T1* cLista<T1>::Buscar(T1* Clave)
{
	unsigned int pos = BuscarAtPos(Clave);

	if (pos < ca)
		return lista[pos];
	return NULL;
}
template <class T1>
unsigned int cLista<T1>::BuscarAtPos(T1* Clave)
{

	for (int i = 0; i < ca; i++)
	{
		if (lista[i] == Clave)
			return i;
	}

	return t;
}

template <class T1>
void cLista<T1>::Listar()
{

	for (int i = 0; i < ca; i++)
	{
		cout << lista[i];
		cout << "----------------------------------------------" << endl;
	}



}