//
// Created by home on 9/11/22.
//

#ifndef ALGORITMOS_NODOLISTA_H
#define ALGORITMOS_NODOLISTA_H


#include <iostream>

typedef struct Dato{
    int id;
    char *origen;
    char *destino;
    int duracion;
    int precio;
} Viaje;



class Nodo {
public:
    Nodo(int dato);

    Nodo(Dato dato);

    Dato dato{};
    Nodo *siguiente;

};

#endif //ALGORITMOS_NODOLISTA_H
