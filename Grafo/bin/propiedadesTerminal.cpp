#include<iostream>
#include<list>
using namespace std;
template <typename T>

class Terminal 
{
    int codigo;
    char* nombre;
    char* ciudad;
    double superficie;
    int cantTermi;
    List<Viajes> destinoNacional; //que son, strings, o viajes? de donde salen los numeros finales 
    List<Viajes> destinoInter; // la lista de proviene, hay que implementarla?


    List<Viajes> viajes;
 
    public Terminal(int codigo, char nombre, char ciudad, double superficie, int cantTermiNode,  Node destinoNacional, Node destinoInter) 
    {
        this.codigo = codigo;
        this.nombre = nombre;
        this.ciudad = ciudad;
        this.superficie = superficie;
        this.codigo = codigo;
        this.cantTermi = cantTermi;
        this.destinoNacional = destinoNacional;
        this.destinoInter = destinoInter;
    }
 
    public: 
    
        getCodigo() 
    {
        return codigo;
    }
 
        void setCodigo(Node codigo) 
    {
        this.codigo = codigo;
    }
 
    public getDestinoNacional() 
    {
        return destinoNacional;
    }
 
    public void setDestinoNacional(Node destinoNacional) 
    {
        this.destinoNacional = destinoNacional;
    }
 
    public getDestinoInter() 
    {
        return destinoInter;
    }
 
    public void setDestinoInter(Node destinoInter) 
    {
        this.destinoInter = destinoInter;
    }
 
    // @Override toma todos los atributos y los pasa a una linea
    public String toString() 
    {
        return "\n Edge [codigo=" + codigo.getCodigo() + ", destinoNacional=" + destinoNacional.getCodigo() + ", destinoInter="
                + destinoInter + "]";
    }
 
};