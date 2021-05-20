#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <list>
#include <allegro.h>
#include "item.h"
using std::cin;
using std::cout;
using std::endl; 
using std::string;
using std::list;

class Jugador{
    private:
        string nombre;
        float vida;
        float ataque;
        float resistencia;
        const static int MAX_ITEMS;
        list< Item * > inventario;
    public:
        Jugador();
        void moverJugador(BITMAP *, BITMAP *, int  , int , int  );
        void teclas(BITMAP *, BITMAP *, int * , int *, int, int, int, int );
};

#endif // JUGADOR_H
