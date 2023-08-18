

#ifndef TATETI_H
#define TATETI_H
#include <string>

using std::string;

// declaracion de funciones  
	
	void pantalla(string ** & tateti, int jugador, int tiros);
	void ejecutarJugada( int fila, int columna, int jugador, string ** & tateti, int tiros); // verifico si  puede hacer una jugada
	bool verificarJugada(int fila, int columna, string ** & tateti);
	void verificarJuego( string ** & tateti, int jugador, int tiros); // checkear estado del juego

#endif                                                                        //
