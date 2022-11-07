#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()

{
  // Creo una cadena
  char cadena[128];
  // Abre un fichero de entrada
  // ifstream datos("D:/Universidad 1er Cuatrimestre 2022/Algoritmos 2022/.vscode/terminales.txt");
  string nombreArchivo = "terminales.txt";
  ifstream datos(nombreArchivo.c_str());

  int sum = 0;
  // std::vector<std::string>;
  // char* nombre_del_vector['a'];
  string RET;
  string COR;

    // while (!datos.eof()) 
    while (getline(datos, RET))
    {

      cout << "Una línea: ";
      cout << RET << endl;
      cout << COR << endl;
    }
    // datos.getline(cadena, 128);
  
  datos.close();
  
  // system("pause");
  
  // cout << cadena << endl;
  
  return 0;
  
}