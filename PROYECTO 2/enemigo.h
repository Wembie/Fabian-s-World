#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <iostream>
#include <list>
#include <allegro.h>
#include "personaje.h"

using std::cin;
using std::cout;
using std::endl; 
using std::string;
using std::list;
//Se crea la clase Enemigo con herencia, con sus diferentes constructores y su metodo de ponerEnemigo
class Enemigo : public Personaje{
    private:
        //
    public:
    	Enemigo();
        Enemigo( string, int, int, int );
        void ponerEnemigo(BITMAP *, BITMAP *, list<int>listaPosicionesEnemigos  );  
        
};

#endif // JUGADOR_H

