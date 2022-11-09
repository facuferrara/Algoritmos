#pragma once
#include "Terminal.h"
#include "Destino.h"
#include <string>
using namespace std;

class Grafo
{
	Terminal* primero;
	int tamano;

public:
	Grafo();
	bool EstaVacio();													//Compruevo si el grafo esta vacio.. TRUE
	int ObtenerTamano();												//Verifico el total de terminales en el Grafo..
	Terminal* ObtenerTerminal(string nombre);								//Obtengo un un terminal por dicho nombre.. ConsultarUnTerminal
	void DarAltaTerminal(string nombre);								//Inserto terminal... DarALTATERMINAL
	void DarAltaDestino(string ori, string dest, int precio);			//Inserto Viaje.... DarALTAVIAJE
	void MostrarListaAdyacencia();										//Muesto toda la lista...  
	void DarBajaTerminal(string nombre);								//Elimino una Terminal... DarBajaTerminal
	void EliminarDestino(string ori, string dest);						//Eliminar Viaje... DarBajaViaje
	void EliminarTodo();												//Eliminar Todo...


	void EliminarDestinos(Terminal* terminal); // Elimina las aristas del vertice especificado
	void EliminarAristasDestino(string dest); // Elimina las aristas que tienen como destino el vertice especificado

	/*void Dijkstra(string origen); // Despliega la ruta más corta entre el origen y los demás vertices*/
};

