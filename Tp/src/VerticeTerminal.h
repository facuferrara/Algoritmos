#pragma once
#include <iostream>

class Arista;

class VerticeTerminal
{
	std::string nombre;
	VerticeTerminal* sig;
	Arista* ari;

	friend class Grafo;
public:
	VerticeTerminal(std::string nombre);
};