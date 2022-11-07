#ifndef ALGORITMOS_VERTICE_H
#define ALGORITMOS_VERTICE_H

#include <iostream>

using namespace std;

class AristaViaje; // Forward declaration

class Vertice {
//Atributos
    string nombre;
    Vertice * siguiente;    //Puntero al siguiente vertice
    AristaViaje * arista;        //Puntero a la primera arista

    //Para poder acceder a los atributos privados de la clase
    friend class Grafo;

//Metodos
public:
    //Constructor
    Vertice(string nombre);

};

#endif //ALGORITMOS_VERTICE_H