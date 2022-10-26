package vuelos;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Scanner;


public class GestionYLecturaDeArchivos  {
    /**
     * Cambiar ubicacion archivo txt de Aeropuertos y Vuelos
     */
    static String aeropuertos_texto = "1/src/main/java/vuelos/aeropuertos.txt";
    static String vuelos_texto = "1/src/main/java/vuelos/vuelos.txt";
	  

    long vV;
    long vuelitos;
   
    ArrayList<Integer> origenArray = new ArrayList<>();
    ArrayList<Integer> destinoArray = new ArrayList<>();
    ArrayList<Integer> costoArray = new ArrayList<>();
    ArrayList<Integer> horasArray = new ArrayList<>();

      
      public void leerArchivoOrdenado(PriorityQueue<String> colaPrioridad) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader(aeropuertos_texto));
        
        vV = in.lines().count();
        String lineaT;
        while ((lineaT = in.readLine()) != null) {

          colaPrioridad.add(lineaT);
          
        }
        in.close();
     
       while (!colaPrioridad.isEmpty()) {
        String mostrarLineaTxt = colaPrioridad.poll();

        System.out.println(mostrarLineaTxt);
        }
}


public void leerArchivoOrdenadolista(PriorityQueue<String> colaPrioridad) throws IOException {
  BufferedReader in = new BufferedReader(new FileReader(aeropuertos_texto));
  
  String lineaT;
  while ((lineaT = in.readLine()) != null) {

    colaPrioridad.add(lineaT);
    
  }
  in.close();

 while (!colaPrioridad.isEmpty()) {
  String mostrarLineaTxt = colaPrioridad.poll();

  System.out.println(mostrarLineaTxt);
  }

}
     
 public void buscarIATA(String codigo) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader(aeropuertos_texto));
        String lineaDeBusqueda;
        boolean encontrado = false;

        while ((lineaDeBusqueda = in.readLine()) != null && !encontrado) {
          String siglas = lineaDeBusqueda.substring(0, 3);
          String[] separarLineaTexto = lineaDeBusqueda.split("\\s+");
          String nombre = separarLineaTexto[1];
          String ciudad = separarLineaTexto[2];
          String pais = separarLineaTexto[3];
          if (siglas.equals(codigo)) {
            System.out.println("El código IATA: " + siglas + "'\n" + " pertenece al aeropuerto '" + nombre + "'\n" + "Ubicado en "
                + ciudad + ", " + pais);
            encontrado = true;
          }
        }
        if (!encontrado) {
          System.out.println("Código IATA no encontrado");
        }
        in.close();
      }

      public void borrarAeropuerto(String borrarLInea) {

        try {
          File lineatxt = new File(aeropuertos_texto);
          if (!lineatxt.isFile()) {
            System.out.println("no existe el archivo");
            return;
          }
        
          File archivoTemporal = new File(lineatxt.getAbsolutePath() + ".tmp");

          BufferedReader br = new BufferedReader(new FileReader(aeropuertos_texto));
          PrintWriter pw = new PrintWriter(new FileWriter(archivoTemporal));

          String lineaT = null;
        
          while ((lineaT = br.readLine()) != null) {
            String siglas = lineaT.substring(0, 3);
            if (!siglas.equals(borrarLInea)) {
              pw.println(lineaT);
              pw.flush();
            }
          }
          pw.close();
          br.close();

         
          if (!lineatxt.delete()) {
            System.out.println("No es posible borrar el archivo");
            return;
          }

        
          if (!archivoTemporal.renameTo(lineatxt))
            System.out.println("No es posible renombrar el archivo");
        } catch (FileNotFoundException ex) {
          ex.printStackTrace();
        } catch (IOException ex) {
          ex.printStackTrace();
        }
      }
      

      public static void darDeAltaAeropuerto() {
        Scanner sn = new Scanner(System.in);

        System.out.print("Codio IATA: ");
        String codigoIATANuevo = sn.next();
        System.out.print("Nombre del aeropuerto: ");
        String nombreAeropuertoNuevo = sn.next();
        System.out.print("Ciudad: ");
        String ciudadNueva = sn.next();
        System.out.print("Pais: ");
        String paisNuevo = sn.next();
        System.out.print("km2: ");
        Float km2Nuevo = sn.nextFloat();
        System.out.print("Terminales: ");
        Integer terminalesNuevo = sn.nextInt();
        System.out.print("Vuelos nacionales: ");
        Integer nacionalesNuevo = sn.nextInt();
        System.out.print("Vuelos internacionales: ");
        Integer internacionalesNuevo = sn.nextInt();

        String guardarNuevo = (codigoIATANuevo + " " + nombreAeropuertoNuevo + " " + ciudadNueva + " " + paisNuevo + " "
            + km2Nuevo + " " + terminalesNuevo + " " + nacionalesNuevo + " " + internacionalesNuevo);

        try {
          BufferedWriter bw = new BufferedWriter(new FileWriter(aeropuertos_texto, true));
          bw.newLine();
          bw.append(guardarNuevo);
          bw.close();
        } catch (IOException e) {
          System.out.println(e.getMessage());
        };
        
      }

      public void lecturaVuelo(PriorityQueue<String> colaPrioridad) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader(vuelos_texto));
        
        vuelitos = in.lines().count();

        String lineaT;
        while ((lineaT = in.readLine()) != null) {
          colaPrioridad.add(lineaT);
        }
        in.close();

      }

      public long getVV() {
		    return vV;
      }
      
      public long getVuelitos() {
        return vuelitos;
        
      }

      public void origenVueloDestinoVuelo() throws IOException {
        BufferedReader in = new BufferedReader(new FileReader(vuelos_texto));
        String lineaDeBusqueda;
        
      
        while ((lineaDeBusqueda = in.readLine()) != null) {
        
         String[] separarLineaTexto = lineaDeBusqueda.split("\\s+");
         String origenVuelo = separarLineaTexto[0];
         Integer origen = AuxiliaresDeIATA.reemplazarIATA(origenVuelo);

          int origenInt =  origen.intValue();
          origenArray.add(origenInt);
        String destinoVuelo = separarLineaTexto[1];
        Integer destino = AuxiliaresDeIATA.reemplazarIATA(destinoVuelo);;
          int destinoInt =  destino.intValue();
          destinoArray.add(destinoInt);
          
        Integer costo = Integer.parseInt(separarLineaTexto[2]);
        costoArray.add(costo);

        Integer horas = Integer.parseInt(separarLineaTexto[3]);
        horasArray.add(horas);
         
        }
        in.close();
      }


      public static void main(String[] args) throws IOException {
        GestionYLecturaDeArchivos gestionarArchivo = new GestionYLecturaDeArchivos();
        
       gestionarArchivo.origenVueloDestinoVuelo();
    }
};