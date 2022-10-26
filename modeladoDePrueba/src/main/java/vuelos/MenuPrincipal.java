package vuelos;

import java.io.IOException;
import java.util.InputMismatchException;
import java.util.PriorityQueue;
import java.util.Scanner;

public class MenuPrincipal {
    static void clearScreen() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }
    private static void pressEnterParaMenu() {
        System.out.println("Volver al menú inicial presionando 'ENTER'...");
        try {
            System.in.read();
        } catch (Exception e) {
        }
    }

    public void menu() throws IOException {
        Scanner sn = new Scanner(System.in);
        boolean salir = false;
        int opcion; 
        PriorityQueue<String> colaPrioridad = new PriorityQueue<>();
        GestionYLecturaDeArchivos gestionarArchivo = new GestionYLecturaDeArchivos();
        CaminoMinimo caminoMinimo = new CaminoMinimo();
        int bandera = 0; 
       

        while (!salir) {
            System.out.println("***************************************************************");
            System.out.println("******************* Menu de Aeropuertos ***********************");
            System.out.println("***************************************************************");
            System.out.println("* 1. Ver Aeropuerto                                           *");
            System.out.println("***************************************************************");
            System.out.println("* 2. Dar de alta aeropuerto                                   *");
            System.out.println("***************************************************************");
            System.out.println("* 3. Dar de baja aeropuerto                                   *");
            System.out.println("***************************************************************");
            System.out.println("* 4. Mostrar todos los aeropuertos (ordenados por código IATA)*");
            System.out.println("***************************************************************");
            System.out.println("* 5. Busqueda de vuelos por ruta mas corta                    *");
            System.out.println("***************************************************************");
            System.out.println("* 6. Busqueda de vuelos por ruta mas barata                   *");
            System.out.println("***************************************************************");
            System.out.println("* 7. Salir                                                    *");
            System.out.println("***************************************************************");

            try {

                System.out.println("Elige una de las opciones");
                opcion = sn.nextInt();

                switch (opcion) {
                    case 1:
                        System.out.println("Ingrese el codigo IATA a buscar: ");
                        String buscarIATAIngresado = sn.next();
                        gestionarArchivo.buscarIATA(buscarIATAIngresado);
                        pressEnterParaMenu();
                        clearScreen();
                        break;
                    case 2:
                        System.out.println("Ingrese los datos para el nuevo Aeropuerto:");
                        GestionYLecturaDeArchivos.darDeAltaAeropuerto();
                        pressEnterParaMenu();
                        clearScreen();
                        break;
                    case 3:
                        System.out.println("Elija el Codigo IATA del aeropuerto que desea borrar");
                        String codigoIATAaBorrar= sn.next();
                        gestionarArchivo.borrarAeropuerto(codigoIATAaBorrar);
                        pressEnterParaMenu();
                        clearScreen();
                        break;
                    case 4:
                        System.out.println("El listado de los aeropuertos es:");
                        gestionarArchivo.leerArchivoOrdenadolista(colaPrioridad);
                        pressEnterParaMenu();
                        clearScreen();

                        break;
                    case 5:
                        System.out.println("5. La Ruta minima mas económica es : ");
                        bandera = 1;    
                        caminoMinimo.ejecutarCamino(bandera);
                        bandera =0;
                        pressEnterParaMenu();
                        clearScreen();
                        break;
                    case 6:
                        System.out.println("6. La Ruta minima por menor tiempo de vuelo es : ");  
                          
                        caminoMinimo.ejecutarCamino(bandera);
                        pressEnterParaMenu();
                        clearScreen();
                        break;
                    case 7:
                        salir = true;
                        break;
                    default:
                        System.out.println("Debe ingresar una opción entre 1 y 7");
                        pressEnterParaMenu();
                        clearScreen();
                }
            } catch (InputMismatchException e) {
                pressEnterParaMenu();
                clearScreen();
                sn.next();
            }
        }
        sn.close();
    }

}