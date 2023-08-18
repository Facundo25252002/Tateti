/*
 * Nombre:Facundo.
 * Trabajo :Hacer Juego TaTeTi
 * 
 * 
 */

#include <cstdlib>                // Para usa comando systen();  y poder ejecutar comandos del sistema
#include<stdio.h>                          
#include <iostream>
#include <string>                
#include "tateti.h"               // Recordatorio  Hacerme libreria  propia con  funciones para llamarlas (header file ... acrchivo  .h (archivo cabecera) ) 
                                  //Recordatorio: Bsucar libreria de colores para c++, y como usarla.   
using namespace std;                //Paso 1:Ingresamos la librería stdlib.h al inicio del código de programa de la siguiente forma:include<stdio.h>
                                    //Paso 2:Dentro del código del programa en la función principal (main), escribimos:system (color “color de fondo” “color de letra”);Codigo de colores :0 = Negro,1= Azul
                                    //*2= Verde, 3= Aguamarina, 4= Rojo, 5= Púrpura, 6= Amarillo, 7= Blanco,8= Gris,9= Azul Claro,A= Verde Claro,B= Aguamarina Claro,C= Rojo Claro,D= Púrpura Claro,E= Amarillo Claro,F= Blanco Brillante .




 
int main(){
	                                    // hacer array tateti, las columnas y filas ,creo los espacios en memoria.
	

	string ** tateti  = new string*[3];
	for (int i = 0 ; i <3; i++){
			tateti[i]=new string[3];                                                                                                                   //el operado  "new" en c++  crea un objeto, y el operador "delete"  borra ese objeto creado
		}                                                                                                                               // en este caso  caso estoy creando un objeto  en  el puntero asignado string[3]
		
    for (int i = 0 ; i <3; i++){
		for (int j = 0 ; j <3; j++){
				tateti[i][j]= "	-	";                                                // aca  se crea el espacio en blanco del tablero.
			}
		}
	
	 	
	pantalla (tateti, 0, 0);
	
	
	return 0;
}


void pantalla(string ** & tateti, int jugador, int tiros){  // funcion que se encarga de raficar mi juego 
	int fila, columna;
	
	cout << "\n			      Ta-Te-Ti             " << endl;                              //Recordatorio: buscar la manera de  dibujar.. 
	cout << "		   ****************************"<<endl;
	cout << "		   *          Pizarra         *"<<endl;
	cout << "		   **************************** "<<endl;
	cout << "		   *         ITES-Games       *"<<endl; 
	cout << "		   ****************************\n\n"<<endl; 
	cout << "	" << tateti[0][0] << "|" << tateti[0][1] << "|" << tateti[0][2] << endl;
	cout << "	   ------------- --------------- --------------" << endl;
	cout << "	" << tateti[1][0] << "|" << tateti[1][1] << "|" << tateti[1][2] << endl;
	cout << "	   ------------- --------------- --------------" << endl;
	cout << "	" << tateti[2][0] << "|" << tateti[2][1] << "|" << tateti[2][2] << endl;
		    
		
			
	
	// Verificar que jugador le toca jugar
	cout << "\n	Como Jugar?!: Solo podes elegir de la fila / columna desde el: 1 hasta el 3." << endl; 
	if (jugador==0){
			cout << "\n	-> El turno es para el primer Jugador(X):" << endl;
	}else{
			cout << "\n	-> El turno es para el Segundo Jugador (O):" << endl;
	}
	
	cout << "		Fila: ";
	cin >> fila;
	
	while((fila<1) || (fila>3)){  
	                                                       //controlar que la  fila introducida de corrcta ,Hacer mensaje de error
		cout << "		Fila erronea, igrese nuevamente: ";
		cin >> fila;
		
	}
	
	cout << "		Columna: ";
	cin >> columna;
	while((columna<1) || (columna>3)){
		cout << "		Columna erronea, igrese nuevamente: ";
		cin >> columna;
	}
	
	if (verificarJugada(fila-1, columna-1, tateti)){                                                                  // -1 para que el jugador no tenga que poner  cunado hace la jugada  0, 1 ,2 
	
		ejecutarJugada(fila-1, columna-1, jugador, tateti, tiros);
	
	}else{
		                   
		cout << "    Lo siento ese movimiento ya se a realizo!!" << endl;
		cout << "			Hacer otro movimiento " << endl;
		pantalla(tateti, jugador, tiros);
	}
}

bool verificarJugada(int fila, int columna, string ** & tateti){       
		
	if (tateti[fila][columna] == "	-	"){                      // comprobar que este "vacia"(usar " -" de reemplazo)
			return true;
	}else {
		return false;
	}	
		
}

void ejecutarJugada( int fila, int columna, int jugador, string ** & tateti, int tiros){
		                                                                                     // Como hacer  para limpiar pantalla con system("clear"); ?
		tiros = tiros + 1;
		
		if(jugador==0){
			tateti[fila][columna] = "	X	";
			verificarJuego(tateti, 1, tiros);
			
		}else{
			tateti[fila][columna] = "	O	";
			verificarJuego(tateti, 0, tiros);
		}
	    
}


void verificarJuego(string ** & tateti, int jugador, int tiros){
	
	string x = "	X	";
	string o = "	O	";
    system ("color 04") ;                           //Poniendo acá el color: system ("color 04") toda la  pantalla cambia; como hago para asignarle color a la variables  x , o ? y que solo me cambie de color  x ,o ( romper y buscar).
    
    
	int op = 0;
	
	if (tiros == 9){   // Hacer jugadas de todas las posciones...
		op = 3;
	}
	
	if (tateti[0][0]==x && tateti[0][1]==x && tateti[0][2]==x ){                  // si se llega maximo de jugadas enviar a case 3  "empate" 
		op = 1;
	}else if (tateti[1][0]==x && tateti[1][1]==x && tateti[1][2]==x ){
		op = 1;
	}else if (tateti[2][0]==x && tateti[2][1]==x && tateti[2][2]==x ){
		op = 1;
	}else if (tateti[0][0]==x && tateti[1][0]==x && tateti[2][0]==x ){
		op = 1;
	}else if (tateti[0][1]==x && tateti[1][1]==x && tateti[2][1]==x ){
		op = 1;
	}else if (tateti[0][2]==x && tateti[1][2]==x && tateti[2][2]==x ){
		op = 1;
	}else if (tateti[0][0]==x && tateti[1][1]==x && tateti[2][2]==x ){
		op = 1;
	}else if (tateti[2][0]==x && tateti[1][1]==x && tateti[0][2]==x ){
		op = 1;
	} 
	
	if (tateti[0][0]==o && tateti[0][1]==o && tateti[0][2]==o ){                   // opciones de ganar enviar a  case 1 o case 2 del switch...
		op = 2;
	}else if (tateti[1][0]==o && tateti[1][1]==o && tateti[1][2]==o ){
		op = 2;
	}else if (tateti[2][0]==o && tateti[2][1]==o && tateti[2][2]==o ){
		op = 2;
	}else if (tateti[0][0]==o && tateti[1][0]==o && tateti[2][0]==o ){
		op = 2;
	}else if (tateti[0][1]==o && tateti[1][1]==o && tateti[2][1]==o ){
		op = 2;
	}else if (tateti[0][2]==o && tateti[1][2]==o && tateti[2][2]==o ){
		op = 2;
	}else if (tateti[0][0]==o && tateti[1][1]==o && tateti[2][2]==o ){
		op = 2;
	}else if (tateti[2][0]==o && tateti[1][1]==o && tateti[0][2]==o ){
		op = 2;
	}
	
	switch(op){
		case 1:
			    cout << "\n	                                  "<<endl;   
				cout << "	       		  * Ta-Te-Ti  *         "<< endl;
				cout << "		   *****************************"<<endl;
				cout << "		   *    Gana jugador 1 (X)     *"<<endl;
				cout << "		   *****************************"<<endl; 
				cout << "		   *****************************"<<endl; 
			    cout << "		   *         ITES-Games        *"<<endl; 
			 	cout << "		   *****************************"<<endl;    	
				
				system ("color 09") ;                                              // Esto me gusta : poniendo el color antes del break  cambio el color  hasta ahi.
			break;
			
		case 2:
		
			 	   
				cout << "\n	     		  * Ta-Te-Ti  *         "<< endl;
				cout << "		   *****************************"<<endl;
				cout << "		   *    Gana jugador 2 (O)     *"<<endl;
				cout << "		   *****************************"<<endl; 
			    cout << "		   *****************************"<<endl; 
			    cout << "		   *         ITES-Games        *"<<endl; 
			 	cout << "		   *****************************"<<endl; 
				system ("color 02") ;    
			break;
			
		case 3:
			
			      
				cout << "\n	    		  * Ta-Te-Ti *          "<< endl;
				cout << "		   *****************************"<<endl;
				cout << "		   *          Empate           *"<<endl;
				cout << "		   *****************************"<<endl; 
				cout << "		   *****************************"<<endl; 
			   cout << "		   *         ITES-Games        *"<<endl; 
			 	cout << "		   *****************************"<<endl;
				 
				system ("color 06") ;    	
			break;
		default: 
					pantalla(tateti , jugador, tiros);
					
			break;
			
		
	}
}



