cmake_minimum_required(VERSION 3.23)
project(Algoritmos)

set(CMAKE_CXX_STANDARD 14)

include_directories(Tp/bin)
include_directories(Tp/src)
include_directories(Tp/Viajes)

add_executable(Algoritmos
        Tp/bin/Destino.cpp
        Tp/bin/Destino.h
        Tp/bin/GestionDatos.cpp
        Tp/bin/GestionDatos.h
        Tp/bin/Grafo.cpp
        Tp/bin/Grafo.h
        Tp/bin/GrafoDinamico.cpp
        Tp/bin/GrafoDinamico.h
        Tp/bin/propiedadesTerminal.cpp
        Tp/bin/Terminal.cpp
        Tp/bin/Terminal.h
        Tp/src/Destino.cpp
        Tp/src/Destino.h
        Tp/src/GestionDatos.cpp
        Tp/src/GestionDatos.h
        Tp/src/Grafo.cpp
        Tp/src/Grafo.h
        Tp/src/GrafoDinamico.cpp
        Tp/src/GrafoDinamico.h
        Tp/src/propiedadesTerminal.cpp
        Tp/src/Terminal.cpp
        Tp/src/Terminal.h
        Tp/Viajes/AristaViaje.cpp
        Tp/Viajes/AristaViaje.h
        Tp/Viajes/GrafoViaje.cpp
        Tp/Viajes/GrafoViaje.h
        Tp/Viajes/VerticeViaje.cpp
        Tp/Viajes/VerticeViaje.h Tp/src/propiedadesTerminal.h Tp/Lista/NodoLista.cpp Tp/Lista/NodoLista.h Tp/Lista/Lista.cpp Tp/Lista/Lista.h)
