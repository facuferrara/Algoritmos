#ifndef ALGORITMOS_GRAFOVIAJES_H
#define ALGORITMOS_GRAFOVIAJES_H

using namespace std;

class GrafoViajes {

    //Atributos
private:
    Vertice * vertice; //Puntero al primer vertice
    int numVertices;    //Numero de vertices

    //Metodos
public:
    //Constructor
    GrafoViajes();

    //Metodos de la clase

    //Pos: Inserta un vertice en el grafo
    void insertarVertice(string nombre);

    //Pos: Inserta una arista en el grafo
    void insertarArista(string origen, string destino, int peso);

    //Pos: Mostar el grafo por pantalla
    void mostrarGrafo();
};


#endif //ALGORITMOS_GRAFOVIAJES_H
