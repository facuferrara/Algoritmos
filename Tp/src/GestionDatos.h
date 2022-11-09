#include <iostream>

class GestionDatos{
private:
    char cadena[128];
    std::string nombreArchivo = "terminales.txt";
    std::ifstream datos(std::string nombreArchivo);
};