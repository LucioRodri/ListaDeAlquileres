#pragma once
#include <string>
#include <iostream>

using namespace std;	//ATENCION: DEBEN AGREGAR LAS EXCEPCIONES CORRESPONDIENTES PARA EVITAR ERRORES CUANDO USEN LA LISTA

#define TMAX 5
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

};									

template <class T1>					
cLista<T1>::cLista(unsigned int T)	
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
	if (P == NULL)//Revisamos que no sea NULL
		throw new exception("\nIngrese un elemento valido!");
	T1* aux;
	try {
		aux = Buscar(P);
	}
	catch(exception* error)
	{
		throw error;
	}
	if (aux != NULL)
		throw new exception("\n¡El elemento esta repetido!"); //revisamos que el elemento no se encuentre repetido
	if (ca < t)//Revisamos que no se supere la capacidad maxima
	{	
		lista[ca++] = P;
	}
	else
		throw new exception("\nSe ha superado el tamanio maximo de la lista!");
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
	if (clave == NULL)//Revisamos que no pase un puntero NULL
		throw new exception("\nElemento a quitar no valido, es null!");

	unsigned int i;
	try {//Revisamos que el elemento se encuentre en la lista
		i = BuscarAtPos(clave);
	}
	catch(exception* error)
	{
		throw error;
	}
	//if (i >= ca)throw new exception("\nLa posicion no es valida!");//Revisamos que el elemento no supere la capacidad actual

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
	try{
		T1* aux = Quitar(clave);
	}
	catch(exception* error)
	{
		throw error;
	}
	if (aux != NULL)
		delete aux;
}
template <class T1>
void cLista<T1>::EliminarenPos(unsigned int pos)
{
	if (pos >= ca)throw new exception("\nLa posicion no es valida!");
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
	unsigned int pos
	try{
		pos = BuscarAtPos(Clave);
	}
	catch(exception* error)
	{
		throw error; //relanzamos la posible excepcion del metodo BuscarAtPos
	}
	if (pos < ca)
		return lista[pos];
	throw new exception("\nNo se encontro");
}
template <class T1>
unsigned int cLista<T1>::BuscarAtPos(T1* Clave)
{
	if (Clave == NULL)
		throw new exception("\nIngrese un elemento valido, diferente a NULL"); //revisamos que pueda buscar algo valido
	for (int i = 0; i < ca; i++)
	{
		if (lista[i] == Clave)
			return i;
	}

	throw new exception("\nNo se encontro"); //si no se encuentra el elemento, lanzamos una excepcion
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