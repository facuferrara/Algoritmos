#pragma once
#include "VerticeTerminal.h"
#include "Arista.h"
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <unordered_set>

using namespace std;
#include "VerticeTerminal.h"

class Grafo
{
	VerticeTerminal* primero;
	int tamano;

public:
	Grafo();
	bool EstaVacio(); // Retorna true si el grafo está vacío
	int ObtenerTamano(); // Retorna el número de VerticeTerminals en el grafo
	VerticeTerminal* ObtenerVerticeTerminal(string nombre); // Retornar el VerticeTerminal que tenga el nombre especificado
	void InsertaVerticeTerminal(string nombre); // Inserta un VerticeTerminal al grafo
	void InsertaArista(string ori, string dest, int precio); // Inserta arista entre los dos VerticeTerminals especificados con el precio especificado
	void MostrarListaAdyacencia(); // Mostrar todos los VerticeTerminals con sus aristas y precios
	void EliminarVerticeTerminal(string nombre); // Elimina el VerticeTerminal con el nombre especificado
	void EliminarArista(string ori, string dest); // Elimina la arista entre los dos VerticeTerminals especificados
	void EliminarTodo(); // Elimina todos los VerticeTerminals y aristas del grafo
	void EliminarAristas(VerticeTerminal* VerticeTerminal); // Elimina las aristas del VerticeTerminal especificado
	void EliminarAristasDestino(string dest); // Elimina las aristas que tienen como destino el VerticeTerminal especificado
	void RecorridoAnchura(string origen); // Recorre el grafo con el algoritmo de anchura
	void RecorridoProfundidad(string origen); // Recorre el grafo con el algoritmo de profundidad
	void PrimeroEnAnchura(string origen, string destino); // Despliega la ruta entre los dos VerticeTerminals especificados con el algoritmo de primero en anchura
	void PrimeroEnProfundidad(string origen, string destino); // Despliega la ruta entre los dos VerticeTerminals especificados con el algoritmo de primero en profundidad
	void PrimeroElMejor(string origen, string destino); // Despliega la ruta entre los dos VerticeTerminals especificados con el algoritmo de primero el mejor
	void MostrarRutaEncontrada(stack<pair<VerticeTerminal*, VerticeTerminal*>> pilaPar, VerticeTerminal* vdest); // Despliega la ruta encontrada
	void Dijkstra(string origen); // Despliega la ruta más corta entre el origen y los demás VerticeTerminals
	void Kruskal(); // Genera el arbol recubridor minimo con el algoritmo de kruskal
	void Prim(string origen);// Genera el arbol recubridor minimo con el algoritmo de Prim
};
