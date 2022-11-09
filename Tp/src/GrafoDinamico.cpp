#include <iostream>
#include  <string>
// #include "pch.h"
#include "Grafo.h"
using namespace std;

int main()
{
	Grafo* grafo = new Grafo();
	int opc = 0;


	grafo->DarAltaTerminal("A");
	grafo->DarAltaTerminal("B");

	grafo->DarAltaDestino("A", "B", 7);

	/*
	grafo->InsertaDestino("A");
	grafo->InsertaDestino("B");

	grafo->InsertaDestino("A", "A", 13);
	grafo->InsertaDestino("A", "D", 8);
	grafo->InsertaDestino("B", "B", 52);
	grafo->InsertaDestino("B", "C", 17);
	*/

	while (opc != 16)
	{
		system("cls");
		cout << "1. Dar de alta una Terminal" << endl; //era vertice
		cout << "2. Insertar destino" << endl; //arista
		cout << "3. Obtener tamano" << endl;
		cout << "4. Mostrar lista de adyacencia" << endl;
		cout << "5. Dar de baja una terminal" << endl;
		cout << "6. Eliminar destino" << endl;
		cout << "7. Eliminar todo" << endl;
		cout << "8. Dijkstra" << endl;
		cout << "9. Salir" << endl;

		cout << endl;
		cout << "Ingrese una opcion del menu: ";
		cin >> opc;

		system("cls");

		switch (opc)
		{
		case 1:
		{
			string nombre;
			cout << "Ingrese el nombre del terminal: ";
			cin >> nombre;

			grafo->DarAltaTerminal(nombre);

			break;
		}
		case 2:
		{
			if (grafo->EstaVacio())
				cout << "El grafo esta vacio" << endl;
			else
			{
				string ori, dest;
				int precio;
				cout << "Ingrese el nombre del terminal origen: ";
				cin >> ori;
				cout << "Ingrese el nombre del terminal destino: ";
				cin >> dest;
				cout << "Ingrese el precio: ";
				cin >> precio;

				grafo->DarAltaDestino(ori, dest, precio);
			}

			break;
		}
		case 3:
		{
			int tamano = grafo->ObtenerTamano();
			cout << "El grafo tiene " << tamano << " terminales" << endl;

			break;
		}
		case 4:
		{
			if (grafo->EstaVacio())
				cout << "El grafo esta vacio" << endl;
			else
				grafo->MostrarListaAdyacencia();

			break;
		}
		case 5:
		{
			if (grafo->EstaVacio())
				cout << "El grafo esta vacio" << endl;
			else
			{
				string nombre;
				cout << "Ingrese el nombre del terminal a eliminar: ";
				cin >> nombre;

				grafo->DarBajaTerminal(nombre);
			}

			break;
		}
		case 6:
		{
			if (grafo->EstaVacio())
				cout << "El grafo esta vacio" << endl;
			else
			{
				string ori, dest;
				cout << "Ingrese el nombre del terminal origen: ";
				cin >> ori;
				cout << "Ingrese el nombre del terminal destino: ";
				cin >> dest;

				grafo->EliminarDestino(ori, dest);
			}
			break;
		}
		case 7:
		{
			if (grafo->EstaVacio())
				cout << "El grafo esta vacio" << endl;
			else
			{
				grafo->EliminarTodo();
			}

			break;
		}
		
		case 8:
		{
			if (grafo->EstaVacio())
				cout << "El grafo esta vacio" << endl;
			else
			{
				string ori;
				cout << "Ingrese el nombre del terminal origen: ";
				cin >> ori;

				grafo->Dijkstra(ori);
			}

			break;
		}
		

		cin.get();
		cin.get();
	}

}