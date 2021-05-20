#ifndef CONTROLLER_H

#include <iostream>
#include <list>
#include <map>

#include "arma.h"
#include "item.h"
#include "jugador.h"
#include "pocion.h"




using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;

class Controller{
    private:
		Jugador jugador;
    public:
        Controller();
        Jugador getJugador();
        list<int> encontrarLimites( int matrizNivel[10][14] );
        void verificarFase(int x, int y, int * faseActual );


};


#endif

