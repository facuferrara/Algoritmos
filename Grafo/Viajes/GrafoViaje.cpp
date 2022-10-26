#include "GrafoViaje.h"

GrafoViajes::GrafoViajes() {
    //Inicializamos los atributos
    vertice = nullptr;
    numVertices = 0;
}

void GrafoViajes::insertarVertice(string nombre) {
    Vertice * nuevo = new Vertice(nombre); //Creamos el nuevo vertice
    nuevo->siguiente = vertices;           // Apuntamos al primer vertice
    vertices = nuevo;                      // Apuntamos al nuevo vertice
    numVertices++;
}

void GrafoViajes::insertarArista(string origen, string destino, int peso) {

    //Buscamos el vertice origen
    Vertice * aux = vertices;

    //Recorremos la lista de vertices
    while (aux != nullptr && aux->nombre != origen){
        aux = aux->siguiente;
    }

    //Si no existe el vertice origen
    if (aux != nullptr){
        aux->arista = new AristaViaje(destino, peso, aux->arista);
    }
}

void GrafoViajes::mostrarGrafo() {
    Vertice* aux = vertices;

    while (aux != nullptr){
        AristaViaje * auxArista = aux->arista;
        cuot << aux->nombre << " -> ";

        while (auxArista != nullptr){
            cout << auxArista->destino->nombre << " ";
            auxArista = auxArista->siguiente;
        }
        cout << endl;
        aux = aux->siguiente;
    }
}

