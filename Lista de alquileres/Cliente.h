#pragma once
#include  <string>
#include <iostream>
using namespace std;

class Cliente
{
private:
	string Nombre_completo;
	string DNI;

public:
	Cliente(string Nombre, string DNI) { Nombre_completo = Nombre;  this->DNI = DNI; };
	~Cliente() { };
	string to_string() {
		return "\nNombre: " + Nombre_completo + "\nDNI: " + DNI;
	};
	void Imprimir() {
		cout << to_string() << endl;
	};
};
