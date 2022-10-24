/**
 * @author raidentrance
 *
 */

#include<iostream>
#include<list>
using namespace std;

template <typename V>

class Viaje
{
    int codigoPartida;
    int codigoDestino;
    int horasViaje;

    //implementar funciones para determinar camino minimo en costo y duracion
 
    public:
        Viaje(int codigoPartida, int codigoDestino, int horasViaje) 
    {
        this.origin = origin;
        this.destination = destination;
        this.distance = distance;
    }

    public:
        NodeOri getOrigin() 
    {
        return origin;
    }
 
    public: 
        void setOrigin(Node origin) 
    {
        this.origin = origin;
    }
 
    public:
        NodeOri getDestination() 
    {
        return destination;
    }
 
    public:
        void setDestination(Node destination) 
    {
        this.destination = destination;
    }
 
    public:
        double getDistance() 
    {
        return distance;
    }
 
    public:
        void setDistance(double distance) 
    {
        this.distance = distance;
    }
 
    // @Override
    public: 
        String toString() 
    {
        return "\n Edge [origin=" + origin.getCity() + ", destination=" + destination.getCity() + ", distance="
                + distance + "]";
    }
 
};