#include "VerticeViaje.h"

Vertice::Vertice(std::string nombre) {

    //Constructor de la clase Vertice
    nombre = std::move(nombre);
    siguiente = nullptr;
    arista = nullptr;
}
