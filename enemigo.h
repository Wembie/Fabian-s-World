#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <iostream>
#include <list>
#include <allegro.h>

using std::cin;
using std::cout;
using std::endl; 
using std::string;
using std::list;

class Enemigo{
    private:
        float vida;
        float ataque;
        float resistencia;
    public:
        Enemigo();
        void ponerEnemigo(BITMAP *, BITMAP *, list<int>listaPosicionesEnemigos  );
        
};

#endif // JUGADOR_H
