// #include<iostream>
#include<list>
using namespace std;

#include "Grafo.h"
template <typename G>


Grafo::Grafo()
{
	primero = NULL;
	tamano = 0;
}

bool Grafo::EstaVacio()
{
	return tamano == 0;
}

int Grafo::ObtenerTamano()
{
	return tamano;
}

VerticeTerminal* Grafo::ObtenerVerticeTerminal(string nombre)
{
	VerticeTerminal* i = primero;

	while (i != NULL)
	{
		if (i->nombre == nombre)
			return i;

		i = i->sig;
	}

	return NULL;
}

void Grafo::InsertaVerticeTerminal(string nombre)
{
	if (ObtenerVerticeTerminal(nombre) == NULL)
	{
		VerticeTerminal* nuevo = new VerticeTerminal(nombre);

		if (EstaVacio())
			primero = nuevo;
		else
		{
			VerticeTerminal* i = primero;

			while (i->sig != NULL)
				i = i->sig;

			i->sig = nuevo;
		}

		tamano++;
	}
	else
		cout << "Ese VerticeTerminal ya existe en el grafo" << endl;
}

void Grafo::InsertaArista(string ori, string dest, int precio)
{
	VerticeTerminal* vori = ObtenerVerticeTerminal(ori);
	VerticeTerminal* vdest = ObtenerVerticeTerminal(dest);

	if (vori == NULL)
		cout << "El VerticeTerminal origen no existe" << endl;

	if (vdest == NULL)
		cout << "El VerticeTerminal destino no existe" << endl;

	if (vori != NULL && vdest != NULL)
	{
		Arista* nueva = new Arista(vdest, precio);

		if (vori->ari == NULL)
			vori->ari = nueva;
		else
		{
			Arista* j = vori->ari;

			while (j->sig != NULL)
				j = j->sig;

			j->sig = nueva;
		}
	}
}

void Grafo::MostrarListaAdyacencia()
{
	VerticeTerminal* i = primero;

	while (i != NULL)
	{
		Arista* j = i->ari;
		cout << i->nombre << " = ";

		while (j != NULL)
		{
			cout << i->nombre << "->" << j->precio << "->" << j->dest->nombre << ",";
			j = j->sig;
		}

		cout << endl;
		i = i->sig;
	}
}

void Grafo::EliminarAristas(VerticeTerminal* VerticeTerminal)
{
	if (VerticeTerminal == NULL)
		return;

	Arista* i = VerticeTerminal->ari;

	while (VerticeTerminal->ari != NULL)
	{
		i = VerticeTerminal->ari;
		VerticeTerminal->ari = VerticeTerminal->ari->sig;
		cout << "Arista " << VerticeTerminal->nombre << "->" << i->dest->nombre << " eliminada" << endl;
		delete(i);
	}
}

void Grafo::EliminarAristasDestino(string dest)
{
	VerticeTerminal* i = primero;

	while (i != NULL)
	{
		if (i->nombre == dest || i->ari == NULL)
		{
			i = i->sig;
			continue;
		}

		if (i->ari->dest->nombre == dest)
		{
			Arista* j = i->ari;
			i->ari = i->ari->sig;
			cout << "Arista " << i->nombre << "->" << dest << " eliminada" << endl;
			delete(j);
		}
		else
		{
			Arista* x = i->ari;
			Arista* y = x->sig;

			while (y != NULL)
			{
				if (y->dest->nombre == dest)
				{
					x->sig = y->sig;
					cout << "Arista " << i->nombre << "->" << dest << " eliminada" << endl;
					delete(y);
				}

				x = y;
				y = y->sig;
			}
		}

		i = i->sig;
	}
}

void Grafo::EliminarVerticeTerminal(string nombre)
{
	if (primero->nombre == nombre)
	{
		VerticeTerminal* i = primero;
		primero = primero->sig;
		EliminarAristas(i);
		EliminarAristasDestino(i->nombre);
		cout << "VerticeTerminal " << nombre << " fue eliminado" << endl;
		delete(i);
		tamano--;
	}
	else
	{
		VerticeTerminal* i = primero;
		VerticeTerminal* j = i->sig;
		bool existe = false;

		while (j != NULL)
		{
			if (j->nombre == nombre)
			{
				i->sig = j->sig;
				EliminarAristas(j);
				EliminarAristasDestino(j->nombre);
				cout << "VerticeTerminal " << nombre << " fue eliminado" << endl;
				delete(j);
				tamano--;
				existe = true;
				break;
			}

			i = j;
			j = j->sig;
		}

		if (!existe)
			cout << "El VerticeTerminal especificado no existe" << endl;
	}
}

void Grafo::EliminarArista(string ori, string dest)
{
	VerticeTerminal* vori = ObtenerVerticeTerminal(ori);
	VerticeTerminal* vdest = ObtenerVerticeTerminal(dest);

	if (vori == NULL)
		cout << "El VerticeTerminal origen no existe" << endl;

	if (vdest == NULL)
		cout << "El VerticeTerminal destino no existe" << endl;

	if (vori != NULL && vdest != NULL)
	{
		if (vori->ari->dest == vdest)
		{
			Arista* i = vori->ari;
			vori->ari = vori->ari->sig;
			cout << "Arista " << ori << "->" << dest << " eliminada" << endl;
			delete(i);
		}
		else
		{
			Arista* i = vori->ari;
			Arista* j = i->sig;

			while (j != NULL)
			{
				if (j->dest == vdest)
				{
					i->sig = j->sig;
					cout << "Arista " << ori << "->" << dest << " eliminada" << endl;
					delete(j);
					break;
				}

				i = j;
				j = j->sig;
			}
		}
	}
}

void Grafo::EliminarTodo()
{
	VerticeTerminal* i = primero;

	while (primero != NULL)
	{
		i = primero;
		primero = primero->sig;
		EliminarAristas(i);
		EliminarAristasDestino(i->nombre);
		cout << "VerticeTerminal " << i->nombre << " eliminado" << endl;
		delete(i);
		tamano--;
	}
}

void Grafo::RecorridoAnchura(string origen)
{
	VerticeTerminal* vOrigen = ObtenerVerticeTerminal(origen);

	if (vOrigen != NULL)
	{
		cout << "Origen: " << origen << endl;
		cout << "En anchura: ";
		queue<VerticeTerminal*> cola;
		list<VerticeTerminal*> lista;
		cola.push(vOrigen);

		while (!cola.empty())
		{
			VerticeTerminal* vActual = cola.front();
			cola.pop();

			list<VerticeTerminal*>::iterator iter = find(lista.begin(), lista.end(), vActual);

			if (iter == lista.end())
			{
				cout << vActual->nombre << ", ";
				lista.push_back(vActual);
			}

			Arista* i = vActual->ari;

			while (i != NULL)
			{
				VerticeTerminal* vDestino = i->dest;
				iter = find(lista.begin(), lista.end(), vDestino);

				if (iter == lista.end())
					cola.push(vDestino);

				i = i->sig;
			}
		}
	}
	else
		cout << "El VerticeTerminal especificado no existe" << endl;
}

void Grafo::RecorridoProfundidad(string origen)
{
	VerticeTerminal* vOrigen = ObtenerVerticeTerminal(origen);

	if (vOrigen != NULL)
	{
		cout << "Origen: " << origen << endl;
		cout << "En profundidad: ";
		stack<VerticeTerminal*> pila;
		list<VerticeTerminal*> lista;
		pila.push(vOrigen);

		while (!pila.empty())
		{
			VerticeTerminal* vActual = pila.top();
			pila.pop();

			list<VerticeTerminal*>::iterator iter = find(lista.begin(), lista.end(), vActual);

			if (iter == lista.end())
			{
				cout << vActual->nombre << ", ";
				lista.push_back(vActual);
			}

			Arista* i = vActual->ari;

			while (i != NULL)
			{
				VerticeTerminal* vDestino = i->dest;
				iter = find(lista.begin(), lista.end(), vDestino);

				if (iter == lista.end())
					pila.push(vDestino);

				i = i->sig;
			}
		}
	}
	else
		cout << "El VerticeTerminal especificado no existe" << endl;
}


void Grafo::PrimeroEnAnchura(string origen, string destino)
{
	VerticeTerminal* vori = ObtenerVerticeTerminal(origen);
	VerticeTerminal* vdest = ObtenerVerticeTerminal(destino);

	if (vori == NULL)
		cout << "El VerticeTerminal origen no existe" << endl;

	if (vdest == NULL)
		cout << "El VerticeTerminal destino no existe" << endl;

	if (vori != NULL && vdest != NULL)
	{
		queue<VerticeTerminal*> cola;
		stack<pair<VerticeTerminal*, VerticeTerminal*>> pilaPar;
		list<VerticeTerminal*> visitados;
		bool rutaEncontrada = false;
		cola.push(vori);

		while (!cola.empty())
		{
			VerticeTerminal* vActual = cola.front();
			cola.pop();

			list<VerticeTerminal*>::iterator iter = find(visitados.begin(), visitados.end(), vActual);

			if (iter == visitados.end())
			{
				if (vActual == vdest)
				{
					rutaEncontrada = true;
					MostrarRutaEncontrada(pilaPar, vdest);
					break;
				}

				visitados.push_back(vActual);
				Arista* i = vActual->ari;

				while (i != NULL)
				{
					VerticeTerminal* dest = i->dest;
					iter = find(visitados.begin(), visitados.end(), dest);

					if (iter == visitados.end())
					{
						cola.push(dest);
						pair<VerticeTerminal*, VerticeTerminal*> par;
						par.first = vActual;
						par.second = dest;
						pilaPar.push(par);
					}

					i = i->sig;
				}
			}
		}

		if (!rutaEncontrada)
			cout << "No existe una ruta entre esos dos VerticeTerminals" << endl;
	}
}

void Grafo::PrimeroEnProfundidad(string origen, string destino)
{
	VerticeTerminal* vori = ObtenerVerticeTerminal(origen);
	VerticeTerminal* vdest = ObtenerVerticeTerminal(destino);

	if (vori == NULL)
		cout << "El VerticeTerminal origen no existe" << endl;

	if (vdest == NULL)
		cout << "El VerticeTerminal destino no existe" << endl;

	if (vori != NULL && vdest != NULL)
	{
		stack<VerticeTerminal*> pila;
		stack<pair<VerticeTerminal*, VerticeTerminal*>> pilaPar;
		list<VerticeTerminal*> visitados;
		bool rutaEncontrada = false;
		pila.push(vori);

		while (!pila.empty())
		{
			VerticeTerminal* vActual = pila.top();
			pila.pop();

			list<VerticeTerminal*>::iterator iter = find(visitados.begin(), visitados.end(), vActual);

			if (iter == visitados.end())
			{
				if (vActual == vdest)
				{
					rutaEncontrada = true;
					MostrarRutaEncontrada(pilaPar, vdest);
					break;
				}

				visitados.push_back(vActual);
				Arista* i = vActual->ari;

				while (i != NULL)
				{
					VerticeTerminal* dest = i->dest;
					iter = find(visitados.begin(), visitados.end(), dest);

					if (iter == visitados.end())
					{
						pila.push(dest);
						pair<VerticeTerminal*, VerticeTerminal*> par;
						par.first = vActual;
						par.second = dest;
						pilaPar.push(par);
					}

					i = i->sig;
				}
			}
		}

		if (!rutaEncontrada)
			cout << "No existe una ruta entre esos dos VerticeTerminals" << endl;
	}
}

bool OrderPorCosto(const pair<VerticeTerminal*, int>& a, const pair<VerticeTerminal*, int>& b)
{
	return a.second < b.second;
}

void Grafo::PrimeroElMejor(string origen, string destino)
{
	VerticeTerminal* vori = ObtenerVerticeTerminal(origen);
	VerticeTerminal* vdest = ObtenerVerticeTerminal(destino);

	if (vori == NULL)
		cout << "El VerticeTerminal origen no existe" << endl;

	if (vdest == NULL)
		cout << "El VerticeTerminal destino no existe" << endl;

	if (vori != NULL && vdest != NULL)
	{
		typedef pair<VerticeTerminal*, int> parVerInt;
		typedef pair<VerticeTerminal*, VerticeTerminal*> parVerVer;
		list<parVerInt> costos, costosOrd;
		stack<parVerVer> pilaPar;
		bool rutaEncontrada = false;
		parVerInt parVI;
		parVI.first = vori;
		parVI.second = 0;
		costos.push_back(parVI);
		costosOrd.push_back(parVI);

		while (!costosOrd.empty())
		{
			VerticeTerminal* vActual = costosOrd.front().first;
			int costoActual = costosOrd.front().second;
			costosOrd.pop_front();

			if (vActual == vdest)
			{
				rutaEncontrada = true;
				MostrarRutaEncontrada(pilaPar, vdest);
				break;
			}

			Arista* i = vActual->ari;

			while (i != NULL)
			{
				VerticeTerminal* dest = i->dest;
				costoActual += i->precio;

				list<parVerInt>::iterator iter = find_if(costos.begin(), costos.end(), [&](const parVerInt& par) { return par.first == dest; });

				if (iter == costos.end())
				{
					parVI.first = dest;
					parVI.second = costoActual;
					costos.push_back(parVI);
					costosOrd.push_back(parVI);
					costosOrd.sort(OrderPorCosto);
					parVerVer parVV;
					parVV.first = vActual;
					parVV.second = dest;
					pilaPar.push(parVV);
				}
				else if (costoActual < iter->second)
				{
					iter->second = costoActual;
					iter = find_if(costosOrd.begin(), costosOrd.end(), [&](const parVerInt& par) { return par.first == dest; });
					iter->second = costoActual;
					costosOrd.sort(OrderPorCosto);
					parVerVer parVV;
					parVV.first = vActual;
					parVV.second = dest;
					pilaPar.push(parVV);
				}

				costoActual -= i->precio;
				i = i->sig;
			}
		}

		if (!rutaEncontrada)
			cout << "No existe una ruta entre esos dos VerticeTerminals" << endl;
	}
}

void Grafo::MostrarRutaEncontrada(stack<pair<VerticeTerminal*, VerticeTerminal*>> pilaPar, VerticeTerminal* vdest)
{
	VerticeTerminal* destinoActual = vdest;

	while (!pilaPar.empty())
	{
		cout << destinoActual->nombre << "<-";

		while (!pilaPar.empty() && pilaPar.top().second != destinoActual)
			pilaPar.pop();

		if (!pilaPar.empty())
			destinoActual = pilaPar.top().first;
	}
}

bool CostoMinimo(const pair<VerticeTerminal*, int>& a, const pair<VerticeTerminal*, int>& b)
{
	return a.second < b.second;
}

void Grafo::Dijkstra(string origen)
{
	VerticeTerminal* vorigen = ObtenerVerticeTerminal(origen);

	if (vorigen == NULL)
		cout << "El VerticeTerminal origen no existe" << endl;
	else
	{
		map<VerticeTerminal*, map<VerticeTerminal*, int>> matriz;
		map<VerticeTerminal*, bool> visitados;
		map<VerticeTerminal*, VerticeTerminal*> rutas;
		map<VerticeTerminal*, int> cola;
		map<VerticeTerminal*, int> distancias;

		VerticeTerminal* vi = primero;

		// Inicializar colecciones de datos
		while (vi != NULL)
		{
			visitados[vi] = false;
			rutas[vi] = NULL;
			distancias[vi] = numeric_limits<int>::max();

			VerticeTerminal* vj = primero;

			while (vj != NULL)
			{
				matriz[vi][vj] = numeric_limits<int>::max();
				vj = vj->sig;
			}

			Arista* aj = vi->ari;

			while (aj != NULL)
			{
				matriz[vi][aj->dest] = aj->precio;
				aj = aj->sig;
			}

			vi = vi->sig;
		}

		distancias[vorigen] = 0;
		visitados[vorigen] = true;
		cola[vorigen] = distancias[vorigen];

		while (!cola.empty())
		{
			// Encuentra el VerticeTerminal con el costo menor en la cola
			map<VerticeTerminal*, int>::iterator iter = min_element(cola.begin(), cola.end(), CostoMinimo);
			visitados[iter->first] = true;

			// Recorre todos los VerticeTerminals que tiene como destino
			Arista* ai = iter->first->ari;

			while (ai != NULL)
			{
				if (!visitados[ai->dest])
				{
					if (distancias[ai->dest] > distancias[iter->first] + matriz[iter->first][ai->dest])
					{
						distancias[ai->dest] = distancias[iter->first] + matriz[iter->first][ai->dest];
						rutas[ai->dest] = iter->first;
						cola[ai->dest] = distancias[ai->dest];
					}
				}

				ai = ai->sig;
			}

			cola.erase(iter->first);
		}

		// Muestra los VerticeTerminals destino con su respectivo peso total
		for (map<VerticeTerminal*, int>::iterator i = distancias.begin(); i != distancias.end(); i++)
			cout << i->first->nombre << ": " << i->second << endl;


		// Muestra las rutas completas
		for (map<VerticeTerminal*, VerticeTerminal*>::iterator i = rutas.begin(); i != rutas.end(); i++)
		{
			VerticeTerminal* vAct = i->first;

			while (vAct != NULL)
			{
				cout << vAct->nombre << " <- ";
				vAct = rutas[vAct];
			}

			cout << endl;
		}
	}
}

void Grafo::Kruskal()
{
	map<VerticeTerminal*, map<VerticeTerminal*, int>> matrizady;
	map<VerticeTerminal*, map<VerticeTerminal*, int>> matrizsol;
	map<VerticeTerminal*, VerticeTerminal*> conectados;

	VerticeTerminal* vi = primero;

	while (vi != NULL)
	{
		conectados[vi] = vi;

		VerticeTerminal* vj = primero;

		while (vj != NULL)
		{
			matrizady[vi][vj] = 0;
			vj = vj->sig;
		}

		Arista* aj = vi->ari;

		while (aj != NULL)
		{
			matrizady[vi][aj->dest] = aj->precio;
			aj = aj->sig;
		}

		vi = vi->sig;
	}


	VerticeTerminal* vA, * vB;
	int aristas = 1;

	while (aristas < tamano)
	{
		int min = numeric_limits<int>::max();

		for (map<VerticeTerminal*, map<VerticeTerminal*, int>>::iterator i = matrizady.begin(); i != matrizady.end(); i++)
		{
			for (map<VerticeTerminal*, int>::iterator j = i->second.begin(); j != i->second.end(); j++)
			{
				if (j->second < min && j->second != 0 && conectados[i->first] != conectados[j->first])
				{
					min = j->second;
					vA = i->first;
					vB = j->first;
				}
			}
		}

		if (conectados[vA] != conectados[vB])
		{
			matrizsol[vA][vB] = min;

			VerticeTerminal* vTemp = conectados[vB];
			conectados[vB] = conectados[vA];

			for (map<VerticeTerminal*, VerticeTerminal*>::iterator i = conectados.begin(); i != conectados.end(); i++)
			{
				if (i->second == vTemp)
					i->second = conectados[vA];
			}

			aristas++;
		}
	}

	for (map<VerticeTerminal*, map<VerticeTerminal*, int>>::iterator i = matrizsol.begin(); i != matrizsol.end(); i++)
	{
		for (map<VerticeTerminal*, int>::iterator j = i->second.begin(); j != i->second.end(); j++)
		{
			cout << i->first->nombre << " <-> " << j->second << " <-> " << j->first->nombre << endl;
		}
	}

}

void Grafo::Prim(string origen)
{
	VerticeTerminal* vOrigen = ObtenerVerticeTerminal(origen);

	if (vOrigen == NULL)
	{
		cout << "El VerticeTerminal origen no existe" << endl;
		return;
	}

	map<VerticeTerminal*, map<VerticeTerminal*, int>> matrizady;
	list<pair<VerticeTerminal*, pair<VerticeTerminal*, int>>> listaSolucion;
	unordered_set<VerticeTerminal*> visitados;

	VerticeTerminal* vi = primero;

	while (vi != NULL)
	{
		VerticeTerminal* vj = primero;

		while (vj != NULL)
		{
			matrizady[vi][vj] = 0;
			vj = vj->sig;
		}

		Arista* aj = vi->ari;

		while (aj != NULL)
		{
			matrizady[vi][aj->dest] = aj->precio;
			aj = aj->sig;
		}

		vi = vi->sig;
	}

	visitados.insert(vOrigen);
	int aristas = 1;

	while (aristas < tamano)
	{
		VerticeTerminal* vMinOrigen, * vMinDestino;
		int precioMin = numeric_limits<int>::max();

		for (unordered_set<VerticeTerminal*>::iterator i = visitados.begin(); i != visitados.end(); i++)
		{
			for (map<VerticeTerminal*, int>::iterator j = matrizady[*i].begin(); j != matrizady[*i].end(); j++)
			{
				if (j->second < precioMin && j->second != 0 && visitados.count(j->first) == 0)
				{
					precioMin = j->second;
					vMinOrigen = *i;
					vMinDestino = j->first;
				}
			}
		}

		listaSolucion.push_back(pair<VerticeTerminal*, pair<VerticeTerminal*, int>>(vMinOrigen, pair<VerticeTerminal*, int>(vMinDestino, precioMin)));
		visitados.insert(vMinDestino);
		aristas++;
	}

	for (list<pair<VerticeTerminal*, pair<VerticeTerminal*, int>>>::iterator i = listaSolucion.begin(); i != listaSolucion.end(); i++)
	{
		cout << i->first->nombre << " <-> " << i->second.second << " <-> " << i->second.first->nombre << endl;
	}
}