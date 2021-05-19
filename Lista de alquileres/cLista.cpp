#include "cLista.h"
template <class T1, class T2, class T3>
cLista<T1, T2, T3>::cLista(unsigned int T)
{
	t = T;
	ca = 0;
	try {
		lista = new T1 * [T];
	}
	catch (...) {
		cerr << "Error generico" << endl;
	}
	for (int i = 0; i < T; i++)
	{
		lista[i] = NULL;
	}
}



template <class T1, class T2, class T3>
cLista<T1, T2, T3>::~cLista(void)
{
	try {
		if (lista != NULL) {
			for (int i = 0; i < ca; i++)
			{
				if (lista[i] != NULL)
					delete lista[i];
			}
			delete[]lista;
		}
	}
	catch (exception* e) {
		throw e;
	}
}

// Metodos Tipicos
template <class T1, class T2, class T3>
void cLista<T1, T2, T3>::Insertar(T1* P)
{
	if (ca < t)
		lista[ca++] = P;
	else throw new exception("No se pueden agregar mas elementos a la lista");
}
template <class T1, class T2, class T3>
void cLista<T1, T2, T3>::Switch(unsigned int pos1, unsigned int pos2) {
	T1* aux = NULL;
	if (pos1 > t || pos2 > t)
		throw new exception("Posicion/es invalida/s");
	aux = lista[pos1];
	lista[pos1] = lista[pos2];
	lista[pos2] = aux;
}

template<class T1, class T2, class T3>
void cLista<T1, T2, T3>::operator+(T1* p)
{
	try {
		Insertar(p);
	}
	catch(exception* error){
		throw error;
	}
}

template <class T1, class T2, class T3>
T1* cLista<T1, T2, T3>::Quitar(T2 clave)
{
	try {
		unsigned int i = BuscarAtPos(clave);
	}
	catch (exception* error)
	{
		throw error;
	}
	if (i >= ca)throw new exception("\nIngrese una posicion valida!");
	T1* aux = NULL;
	aux = lista[i];
	ca--;
	for (unsigned int j = i; j < ca; j++)
	{
		lista[j] = lista[j + 1];

	}
	lista[ca] = NULL;
	return aux;
}

template <class T1, class T2, class T3>
T1* cLista<T1, T2, T3>::Quitar(T3 clave)
{
	unsigned int i = BuscarAtPos(clave);
	if (i >= ca)throw new exception("\nIngrese una posicion valida!");
	T1* aux = NULL;
	try{
	aux = lista[i];
	}
	catch(exception* error)
	{
		throw error;
	}
	ca--;
	for (unsigned int j = i; j < ca; j++)
	{
		lista[j] = lista[j + 1];

	}
	lista[ca] = NULL;
	return aux;
}

template <class T1, class T2, class T3>
T1* cLista<T1, T2, T3>::QuitarPos(unsigned int pos) {

	if (pos >= ca) throw new exception("\nIngrese una posicion valida!");
	T1* aux = NULL;
	try {
		aux = lista[pos];
	}
	catch (exception* error){
		throw error;
	}
	ca--;
	for (unsigned int j = pos; j < ca; j++)
	{
		lista[j] = lista[j + 1];
	}
	lista[ca] = NULL;
	return aux;
}

template <class T1, class T2, class T3>
void cLista<T1, T2, T3>::Eliminar(T2 clave)
{
	try {
		T1* aux = Quitar(clave);
	}
	catch(exception* error){
}		throw error
	if (aux != NULL)
		delete aux;
	else throw new exception("No se pudo eliminar");
}

template <class T1, class T2, class T3>
void cLista<T1, T2, T3>::Eliminar(T3 clave)
{
	T1* aux = Quitar(clave);
	if (aux != NULL)
		delete aux;
	else else throw new exception("No se pudo eliminar");
}

template <class T1, class T2, class T3>
void cLista<T1, T2, T3>::EliminarenPos(unsigned int pos)
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

template <class T1, class T2, class T3>
unsigned int cLista<T1, T2, T3>::BuscarAtPos(T2 Clave)
{
	for (int i = 0; i < ca; i++)
	{
		if (*lista[i] == Clave)
			return i;
	}
	throw new exception("\nNo se encontro");
}

template <class T1, class T2, class T3>
unsigned int cLista<T1, T2, T3>::BuscarAtPos(T3 Clave)
{
	for (int i = 0; i < ca; i++)
	{
		if (*lista[i] == Clave)
			return i;
	}
	throw new exception("\nNo se encontro");
}

template <class T1, class T2, class T3>
T1* cLista<T1, T2, T3>::Buscar(T2 Clave)
{
	unsigned int pos = BuscarAtPos(Clave);

	if (pos < ca)
		return lista[pos];
	throw new exception("\nNo se encontro");
}

template <class T1, class T2, class T3>
T1* cLista<T1, T2, T3>::Buscar(T3 Clave)
{
	unsigned int pos = BuscarAtPos(Clave);

	if (pos < ca)
		return lista[pos];
	throw new exception("\nNo se encontro");
}