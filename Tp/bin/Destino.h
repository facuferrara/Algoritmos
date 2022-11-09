#pragma once
#include <iostream>

class Terminal;

class Destino
{
	int precio;
	Destino* sig;
	Terminal* dest;

	friend class Grafo;
public:
	Destino(Terminal* _dest, int precio);
};