#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "GestionDatos.h"
using namespace std;

// int main()
class GestionDatos
{
  // Creo una cadena
  char cadena[128];
  // Abre un fichero de entrada
  // ifstream datos("D:/Universidad 1er Cuatrimestre 2022/Algoritmos 2022/.vscode/terminales.txt");
  string nombreArchivo = "terminales.txt";
  ifstream datos(std::string nombreArchivo);

  int sum = 0;
  // std::vector<std::string>;
  // char* nombre_del_vector['a'];
  string RET;
  string COR;

  while (getline(datos, RET))
  {
      cout << RET << endl;
      cout << COR << endl;
  }

  datos.close();

  // system("pause");
  
  // cout << cadena << endl;
  
  return 0;
  
};