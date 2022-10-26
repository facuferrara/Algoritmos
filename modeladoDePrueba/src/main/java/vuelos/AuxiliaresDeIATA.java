package vuelos;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

public class AuxiliaresDeIATA {
static String aeropuertos_texto = "1/src/main/java/vuelos/aeropuertos.txt";


/*  public String convertirIntString(Integer codigo) {
      //Tengo que pasar codigo a string y separar en 2 char para pasarlo a int
      //y ese int converirlo en letras correspondiente a ascii
      BigInteger cod = BigInteger.valueOf(codigo);
      //Aca lo estoy conviertiendo a String
      String toStringBigDec=cod.toString();
      String[] dig = toStringBigDec.split("");
      //Ahora quiero separar ese string en grupo de 2 caracteres
      String tupla1 = dig[0] + dig[1];
      System.out.println("Ver la 1er tupl"+tupla1);

      String tupla2 = dig[2] + dig[3];
      System.out.println("Ver la 1er tupl"+tupla2);

      String tupla3 = dig[4] + dig[5];
      System.out.println("Ver la 1er tupl"+tupla3);

      //Esas tuplas las convierto a Int para validar con ASCII y devuelva el codigo en letras

      Integer tuplaNumero1 = Integer.parseInt(tupla1);
      String letra1 = Character.toString(tuplaNumero1);
      Integer tuplaNumero2 = Integer.parseInt(tupla2);
      String letra2 = Character.toString(tuplaNumero2);
      Integer tuplaNumero3 = Integer.parseInt(tupla3);
      String letra3 = Character.toString(tuplaNumero3);

      String iataReconvertido = letra1+letra2+letra3;
      System.out.println("todo letra"+iataReconvertido);

      return iataReconvertido;
    }
*/
 /*   public static BigInteger convertirStringAInt(String codigoIata) {

      StringBuilder sb = new StringBuilder();
      for (char c : codigoIata.toCharArray())
          sb.append((int)c);

      BigInteger iataNumericoOrigen = new BigInteger(sb.toString());
    
      System.out.println("iataNumericoOrigen: "+iataNumericoOrigen);

      return iataNumericoOrigen;
    

    }
*/
/*
    //Alternativa de conversor
    public static int conversorDeStringAInt(String codigo){
      char[] caracteres = codigo.toCharArray();

      String codigoEnString = String.valueOf((int) caracteres[0]) + String.valueOf((int) caracteres[1]) + String.valueOf((int) caracteres[2]); 
      System.out.println("conversor: "+codigoEnString);

      return Integer.parseInt(codigoEnString);

  }
*/
        // Buscar por codigo IATA
        public static Integer reemplazarIATA(String codigo) throws IOException {
          BufferedReader in = new BufferedReader(new FileReader(aeropuertos_texto));
          String lineaDeBusqueda;
          boolean encontrado = false;
          Integer linea = 0;
          while ((lineaDeBusqueda = in.readLine()) != null && !encontrado) {
            // guardo el numero de linea
            linea = linea + 1;
            String siglas = lineaDeBusqueda.substring(0, 3);
            if (siglas.equals(codigo)) {
              encontrado = true;
            }

          }
          if (!encontrado) {
            System.out.println("El aeropuerto no existe");
          }
          in.close();
        return linea;
      }

    // Buscar por codigo IATA
    public static String reemplazarINT(int codigo) throws IOException {
      BufferedReader in = new BufferedReader(new FileReader(aeropuertos_texto));
      String lineaDeBusqueda;
      boolean encontrado = false;
      Integer linea = 0;
      String siglas = null;

      
      while ((lineaDeBusqueda = in.readLine()) != null && !encontrado) {
        // guardo el numero de line
          linea = linea + 1;
          siglas = lineaDeBusqueda.substring(0, 3);
          if (codigo == linea) {
              encontrado = true;
          }
        }
      
      if (!encontrado) {
          System.out.println("El aeropuerto no existe");
      }
      
      in.close();
      return siglas;
    }
/*
        public static void main(String[] args) throws IOException {
        //  GestionYLecturaDeArchivos gestionarArchivo = new GestionYLecturaDeArchivos();
          // Solo imprime el primer elemento sin sacarlo
          // System.out.println(colaPrioridad.element());
          // Sacar una linea
          // System.out.println(colaPrioridad.remove());
          //Scanner sn = new Scanner(System.in);
          //System.out.println("Elija el Codigo IATA del aeropuerto de origen");
          //int codigo = sn.nextInt();
          //AuxiliaresDeIATA.reemplazarINT(codigo);
      // gestionarArchivo.llenarcolaPrioridadAeropuertos();
      // gestionarArchivo.leerArchivoOrdenado(colaPrioridad);
      //gestionarArchivo.conversorDeStringAInt(codigoIATA);
      //System.out.println("pasar el codigo numerico");
      //Scanner st = new Scanner(System.in);
      //BigInteger codigo = st.nextBigInteger();
      //gestionarArchivo.convertirIATAIntaString(codigo);
  }
  */
}
