#include<iostream>
#include<list>
using namespace std;

/**
 * @author raidentrance
 *
 */
template <typename T>
class Terminal 
{
    Node codigo;
    Node nombre;
    Node ciudad;
    double superficie;
    Node cantTermiNode;
    Node destinoNacional;
    Node destinoInter;
    List<Viajes> viajes;
 
    public Terminal(Node codigo, Node nombre, Node ciudad, double superficie, Node cantTermiNode,  Node destinoNacional, Node destinoInter) 
    {
        this.codigo = codigo;
        this.nombre = nombre;
        this.ciudad = ciudad;
        this.superficie = superficie;
        this.codigo = codigo;
        this.cantTermiNode = cantTermiNode;
        this.destinoNacional = destinoNacional;
        this.destinoInter = destinoInter;
    }
 
    public: 
    
        Node getCodigo() 
    {
        return codigo;
    }
 
        void setCodigo(Node codigo) 
    {
        this.codigo = codigo;
    }
 
    public Node getDestinoNacional() 
    {
        return destinoNacional;
    }
 
    public void setDestinoNacional(Node destinoNacional) 
    {
        this.destinoNacional = destinoNacional;
    }
 
    public Node getDestinoInter() 
    {
        return destinoInter;
    }
 
    public void setDestinoInter(Node destinoInter) 
    {
        this.destinoInter = destinoInter;
    }
 
    // @Override
    public String toString() 
    {
        return "\n Edge [codigo=" + codigo.getCodigo() + ", destinoNacional=" + destinoNacional.getCodigo() + ", destinoInter="
                + destinoInter + "]";
    }
 
};