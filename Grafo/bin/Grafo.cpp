#include<iostream>
#include<list>
using namespace std;
#include "Grafo.h";
template <typename G>

class Grafo 
{
 
    private List<Nodo> nodos;
 
    // public void addNode(NodeOri node) 
    // {
    //     if (nodes == null) 
    //     {
    //         nodes = new ArrayList<>();
    //     }
    //     nodes.add(node);
    // }

    public void agregarNodoTerminal(Terminal terminal) 
	    {
	            this->dato = d   //el ultimo nodo apunta a null
				this.next = next; // si queres apuntar a otro necesitas cabeza y siguiente?
	    }
 
    public List<NodeOri> getNodes() 
    {
        return nodes;
    }
 
    // @Override
    public String toString() 
    {
        return "Grafo [nodes=" + nodes + "]";
    }
 
};