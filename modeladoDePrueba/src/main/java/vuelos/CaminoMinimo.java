//package Others;
package vuelos;

import java.io.IOException;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * CaminoMinimo
 */
public class CaminoMinimo {

    public void ejecutarCamino(int bandera) throws IOException {
        PriorityQueue<String> colaPrioridad = new PriorityQueue<>();
        GestionYLecturaDeArchivos gestionarArchivo = new GestionYLecturaDeArchivos();
        gestionarArchivo.leerArchivoOrdenado(colaPrioridad);
        gestionarArchivo.lecturaVuelo(colaPrioridad);
        gestionarArchivo.origenVueloDestinoVuelo();

        int origen, destino;
        int E , peso , inicial, V;
       //Aca trae la cantidad de aeropuertos
        V = (int) gestionarArchivo.getVV();
        //Aca trae la cantidad de vuelos
        E =  (int) gestionarArchivo.getVuelitos();
       
        Dijkstra dijkstraAlgorithm = new Dijkstra(V);
        Scanner sc = new Scanner( System.in );      //para lectura de datos

        for( int i = 0 ; i < E ; i++ ){
            //Se carga el origen de vuelos
            origen = (int) gestionarArchivo.origenArray.get(i);
            //Se carga el destino de los vuelos
           destino = (int) gestionarArchivo.destinoArray.get(i);
            if (bandera == 1){
           //Carga el peso de la arista por precio
           peso = (int) gestionarArchivo.costoArray.get(i);
            } else {
           //Carga el peso de la arista por hora
             peso = (int) gestionarArchivo.horasArray.get(i);
            }
           dijkstraAlgorithm.addEdge(origen, destino, peso, true);
        }
        System.out.print("Ingrese el aeropuerto de origen: ");
        //ACa pones a mano el origen en IATA
        String inicialLetra;
        inicialLetra = sc.next();
        inicial = AuxiliaresDeIATA.reemplazarIATA(inicialLetra);
        dijkstraAlgorithm.dijkstra(inicial);
        dijkstraAlgorithm.printShortestPath();
    }
 }