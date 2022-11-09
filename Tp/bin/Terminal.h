#pragma once
#include <iostream>

class Destino;

class Terminal
{
	std::string nombre;
	Terminal* sig;
	Destino* ari;

	friend class Grafo;

public:
	Terminal(std::string nombre);

};