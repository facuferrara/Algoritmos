#pragma once
#include <iostream>

class VerticeTerminal;

class Arista
{
	int precio;
	Arista* sig;
	VerticeTerminal* dest;

	friend class Grafo;
public:
	Arista(VerticeTerminal* _dest, int precio);
};