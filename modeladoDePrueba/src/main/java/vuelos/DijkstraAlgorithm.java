package vuelos;

import java.util.*;
import java.util.PriorityQueue;
import java.io.IOException;

class Dijkstra {
    
    static String vuelos_texto = "src/main/java/vuelos/vuelos.txt";
    private final int MAX = 4294725;  //maximo numero de vértices
    private final int INF = 1<<30;  //definimos un valor grande que represente la distancia infinita inicial, basta conque sea superior al maximo valor del peso en alguna de las aristas
    
    private List< List< Node > > ady = new ArrayList< List< Node > >(); //lista de adyacencia
    private int distancia[ ] = new int[ MAX ];          //distancia[ u ] distancia de vértice inicial a vértice con ID = u
    private boolean visitado[ ] = new boolean[ MAX ];   //para vértices visitados
    private PriorityQueue< Node > Q = new PriorityQueue<Node>(); //priority queue propia de Java, usamos el comparador definido para que el de menor valor este en el tope
    private int V;                                      //numero de vertices
    private int previo[] = new int[ MAX ];              //para la impresion de caminos
    private boolean dijkstraEjecutado;

    public String banderaIATA;
    public int bandera = 1; 
    
    Dijkstra(int V){
        this.V = V;
        for( int i = 0 ; i <= V ; ++i ) 
            ady.add(new ArrayList<Node>()) ; //inicializamos lista de adyacencia
        dijkstraEjecutado = false;
    }
    
    class Node implements Comparable<Node>{
        int first, second;
        Node( int d , int p ){                          //constructor
            this.first = d;
            this.second = p;
        }
        public int compareTo( Node other){              //es necesario definir un comparador para el correcto funcionamiento del PriorityQueue
            if( second > other.second ) return 1;
            if( second == other.second ) return 0;
            return -1;
        }
    };
    
    //función de inicialización
    private void init(){
        for( int i = 0 ; i <= V ; ++i ){
            distancia[ i ] = INF;  //inicializamos todas las distancias con valor infinito
            visitado[ i ] = false; //inicializamos todos los vértices como no visitados
            previo[ i ] = -1;      //inicializamos el previo del vertice i con -1
        }
    }

    //Paso de relajacion
    private void relajacion( int actual , int adyacente , int peso ){
        //Si la distancia del origen al vertice actual + peso de su arista es menor a la distancia del origen al vertice adyacente
        if( distancia[ actual ] + peso < distancia[ adyacente ] ){
            distancia[ adyacente ] = distancia[ actual ] + peso;  //relajamos el vertice actualizando la distancia
            previo[ adyacente ] = actual;                         //a su vez actualizamos el vertice previo
            Q.add( new Node( adyacente , distancia[ adyacente ] ) ); //agregamos adyacente a la cola de prioridad
        }
    }

    public void dijkstra( int inicial ) throws IOException {
        init(); //inicializamos nuestros arreglos
        Q.add( new Node( inicial , 0 ) ); //Insertamos el vértice inicial en la Cola de Prioridad
        distancia[ inicial ] = 0;      //Este paso es importante, inicializamos la distancia del inicial como 0
        int actual , adyacente;
        int peso;
        while( !Q.isEmpty() ){                   //Mientras cola no este vacia
            actual = Q.element().first;            //Obtengo de la cola el nodo con menor peso, en un comienzo será el inicial
            Q.remove();                           //Sacamos el elemento de la cola
            if( visitado[ actual ] ) continue; //Si el vértice actual ya fue visitado entonces sigo sacando elementos de la cola
            visitado[ actual ] = true;         //Marco como visitado el vértice actual

            for( int i = 0 ; i < ady.get( actual ).size() ; ++i ){ //reviso sus adyacentes del vertice actual
                adyacente = ady.get( actual ).get( i ).first;   //id del vertice adyacente
                peso = ady.get( actual ).get( i ).second;        //peso de la arista que une actual con adyacente ( actual , adyacente )
                if( !visitado[ adyacente ] ){        //si el vertice adyacente no fue visitado
                    relajacion( actual , adyacente , peso ); //realizamos el paso de relajacion
                }
            }
        }
        String iataInicialString = AuxiliaresDeIATA.reemplazarINT(inicial);
        System.out.printf("Caminos mas cortos iniciandos en el aeropuerto %s\n" , iataInicialString );
        for( int i = 1 ; i <= V ; ++i ){
            String ver = AuxiliaresDeIATA.reemplazarINT(i);
            System.out.printf("El camino mas corto desde el aeropuerto %s , hasta el aeropuerto %s es = %d\n" , iataInicialString , ver , distancia[ i ] );
            int val = distancia[i];
            //System.out.printf("imprimo val " +val);
            if (val > 500000 ) {
                banderaIATA = ver;
            }
                
        }
        dijkstraEjecutado = true;
    }
    
    void addEdge( int origen , int destino , int peso , boolean dirigido ){
        ady.get( origen ).add( new Node( destino , peso ) );    //grafo diridigo
        if( !dirigido )
            ady.get( destino ).add( new Node( origen , peso ) ); //no dirigido
    }
    
    void printShortestPath() throws IOException {
        if( !dijkstraEjecutado ){
            System.out.println("Es necesario ejecutar el algorithmo de Dijkstra antes de poder imprimir el camino mas corto");
            return;
        }
        Scanner sc = new Scanner( System.in );      //para lectura de datos
        System.out.println("\n**************Impresion de camino mas corto**************");
        System.out.printf("Ingrese aeropuerto destino: ");
        //Ingrese el codigo IATA
        String destinoLetras;
        int destino;
        destinoLetras = sc.next();
        destino = AuxiliaresDeIATA.reemplazarIATA(destinoLetras);
        printIATA( destino);
        System.out.printf(" \n");
        
    }
    
    //Impresion del camino mas corto desde el vertice inicial y final ingresados
    void print( int destino ){
        if( previo[ destino ] != -1 )    //si aun poseo un vertice previo
            print( previo[ destino ] );  //recursivamente sigo explorando
        System.out.printf("%d " , destino );        //terminada la recursion imprimo los vertices recorridos
    }

    //Impresion del camino mas corto desde el vertice inicial y final ingresados - Impreso IATA
    void printIATA( int destino) throws IOException {
        String destinoIata = AuxiliaresDeIATA.reemplazarINT(destino);
        
            if (destinoIata.equals(banderaIATA)){
                System.out.printf(" No existen vuelos para %s ", destinoIata); 
            } else {

                    if( previo[ destino ] != -1 ){    //si aun poseo un vertice previo
                        printIATA( previo[ destino ]);  //recursivamente sigo explorando
                        destinoIata = AuxiliaresDeIATA.reemplazarINT(destino);
                    }
                    System.out.printf(" -> %s ", destinoIata );        //terminada la recursion imprimo los vertices recorridos
            }
        }
    

    public int getNumberOfVertices() {
        return V;
    }

    public void setNumberOfVertices(int numeroDeVertices) {
        V = numeroDeVertices;
    }

 
}