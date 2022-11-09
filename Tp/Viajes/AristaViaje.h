#ifndef ALGORITMOS_NODOVIAJE_H
#define ALGORITMOS_NODOVIAJE_H
#include <iostream>
#include <string>
#include "VerticeViaje.h"

// Estrcutura de datos que representa un nodo de un grafo de viajes
struct Viaje{
    std::string  codPartida;
    std::string  codDestino;
    int     costoViaje;
    int     tiempoViaje;
};


// Clase que representa un Arista de un grafo de viajes
class AristaViaje {

    // Atributos
private:
    Viaje       viaje;
    AristaViaje *siguiente; // Puntero al siguiente nodo de la lista de adyacencia
    Vertice *destino;  // Puntero al vertice destino de la arista

    // Para poder acceder a los atributos privados de la clase
    friend class GrafoViaje;
    //Metodos
public:
    // Constructor
    AristaViaje(Viaje viaje, Vertice *destino);
};


#endif //ALGORITMOS_NODOVIAJE_H