//
// Created by home on 9/11/22.
//

#ifndef ALGORITMOS_LISTA_H
#define ALGORITMOS_LISTA_H

#include "NodoLista.h"

class Lista {
private:
    void insertar(Dato dato, Nodo *nodo);
    void imprimir(Nodo *nodo);
    void eliminar(Nodo *nodo, Dato dato);

public:
    int tamanio = 0;
    Nodo *primero{};
    void insertar(Dato dato);
    void eliminar(Dato viaje);
    void imprimir();
    bool estaVacia();
    void imprimirListaCompleta();
};


#endif //ALGORITMOS_LISTA_H
