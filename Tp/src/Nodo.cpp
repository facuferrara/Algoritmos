	#include<iostream>
	#include<list>
	using namespace std;

	/**
	 * @author raidentrance
	 *
	 */

	template <typename T>
	typedef int Datos;

	class Nodo {
	    // T terminal;
		// Datos* datos; 
		// Nodo* next;

	    // List<Terminal> terminales;
	 
		public: 
			Nodo(int v, Nodo *sig = NULL){
				valor = v;
				siguiente = siguiente;
			}
			
			private:
				int valor;
				Nodo *siguiente;

				friend class Terminal;
	
		//Es necesario crear una lista para las terminaless?? 

		public: 
			Nodo obtenerDato()
			{
				return this->dato;
			}
			
		public: 
			Nodo asignarSiguienteNodo(Nodo* next )
			{
				return this->dato;
			}		

		public: 
			Nodo obtenerSiguientePuntero(Nodo* next )
			{
				return this->dato;
			}	
	 
	    
	 
	    // @Override
	    // public String toString() 
	    // {
	    //     return "\n \tNodo [terminal=" + terminal + ", termis=" + termis + "]";
	    // }
	};

