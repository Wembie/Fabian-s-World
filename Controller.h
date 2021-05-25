#ifndef CONTROLLER_H

#include <iostream>
#include <list>
#include <map>

#include "arma.h"
#include "item.h"
#include "pocion.h"
#include "personaje.h"
#include "jugador.h"
#include "enemigo.h"

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;

class Controller{
    private:
		Jugador jugador;
		Enemigo enemigo;
		Personaje personaje;		
    public:
        Controller();
        Jugador getJugador();
        Enemigo getEnemigo();
        list<int> encontrarLimites( int matrizNivel[10][14] );
        void verificarFase(int * x, int * y, int * faseActual);
        list<int> encontrarPosicionesEnemigos( int matrizNivel[10][14] );
        Personaje getPersonaje();
        void verificarFaseBatalla(int * x, int * y, int * faseActualBatalla);
        void mostrarNumero(int , BITMAP * , int , int , BITMAP *);
        void mostrarDatosPersonaje(BITMAP *, BITMAP *);
        void mostrarDatosEnemigo(BITMAP *, BITMAP *, Enemigo);
        
};
#endif
