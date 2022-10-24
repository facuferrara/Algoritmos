	#include<iostream>
	#include<list>
	using namespace std;

	/**
	 * @author raidentrance
	 *
	 */

	template <typename T>
	typedef int Datos;

	class Nodo
	{
	    T terminal;
		Datos* datos; 
		Nodo* next;

	    List<Terminal> terminales;
	 
	    // public Nodo(String terminal) 
	    // {
	    //     this.terminal = terminal;
	    // }
		public: 
			T getDato()
			{
				return this->dato;
			}
			
			void setDato(T dato, Nodo* next)
			{
				this->dato = d
				this.next = next;
			}

		public: 
			T obtenerDato()
			{
				return this->dato;
			}
			
		public: 
			T asignarSiguienteNodo(Nodo* next )
			{
				return this->dato;
			}		

		public: 
			T obtenerSiguientePuntero(Nodo* next )
			{
				return this->dato;
			}	
	 
	    public void agregarNodoTerminal(Terminal terminal) 
	    {
	            this->dato = d   //el ultimo nodo apunta a null
				this.next = next; // si queres apuntar a otro necesitas cabeza y siguiente?
	    }
	 
	    // @Override
	    // public String toString() 
	    // {
	    //     return "\n \tNodo [terminal=" + terminal + ", termis=" + termis + "]";
	    // }
	};

