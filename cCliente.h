#pragma once
#include  <string>

using namespace std;

class Cliente
{
private:
	string Nombre_completo;
	string DNI;

public:
	Cliente(string Nombre, string DNI) { Nombre_completo = Nombre;  this->DNI = DNI; };
	~Cliente() { };
};
