#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(void){

    int opcion;

    int opc=0;
        do
        {
            system("cls");
            cout<<"Menu Principal"<<endl;
            cout<<"1. "<<endl;
            cout<<"2. "<<endl;
            cout<<"3. "<<endl;
            cout<<"4. "<<endl;

            cout<<"Ingrese la opcion deseada : "<<endl;
            cin>>opcion;

            switch( opcion ) 
            {
                case 0: cout<<"Mostrar todas las terminales" ;
                        cin>>opc;
                        break;

                case 1: cout<<"Consultar por una terminal" ;
                        cin>>opc;
                        break;
                        
                case 2: cout<<"Dar de alta una terminal " <<opc;
                                //ejecuto una funcion
                        getch(); //pausa
                        break;

                case 3: cout<<"Dar de baja una terminal : ";
                
                        getch();
                        break;

                default: cout<<"La opcion ingresada no es valida";
                        getch();
                        break;
            }

        } while ( opcion!=0);
        
}
