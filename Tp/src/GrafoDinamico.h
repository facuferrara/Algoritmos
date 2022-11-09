#include <stack>
#include <map>
#include <unordered_set>

using namespace std;

class Terminal;

class Grafo
{
	Terminal* primero;
	int tamano;

public:
	Grafo();
	bool EstaVacio(); // Retorna true si el grafo está vacío
	int ObtenerTamano(); // Retorna el número de vertices en el grafo
	Terminal* ObtenerTerminal(string nombre); // Retornar el vertice que tenga el nombre especificado
	void DarAltaTerminal(string nombre); // Inserta un vertice al grafo
	void DarAltaDestino(string ori, string dest, int precio); // Inserta arista entre los dos vertices especificados con el precio especificado
	/*void MostrarListaAdyacencia(); // Mostrar todos los vertices con sus aristas y precios*/
	void DarBajaTerminal(string nombre); // Elimina el vertice con el nombre especificado
	void EliminarDestino(string ori, string dest); // Elimina la arista entre los dos vertices especificados
	void EliminarTodo(); // Elimina todos los vertices y aristas del grafo
	void EliminarDestinos(Terminal* terminal); // Elimina las aristas del vertice especificado
	/*
	void EliminarAristasDestino(string dest); // Elimina las aristas que tienen como destino el vertice especificado

	void MostrarRutaEncontrada(stack<pair<Terminal*, Terminal*>> pilaPar, Terminal* vdest); // Despliega la ruta encontrada
	*/
	//void Dijkstra(string origen); // Despliega la ruta más corta entre el origen y los dem
};