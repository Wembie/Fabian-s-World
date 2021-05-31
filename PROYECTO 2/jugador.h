#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <list>
#include <allegro.h>
#include "item.h"
#include "personaje.h"
#include "arma.h"
#include "pocion.h"

using std::cin;
using std::cout;
using std::endl; 
using std::string;
using std::list;
//Se crea la clase Jugador con herencia a Personaje, con sus respetivos atributos, constructor y metodos
class Jugador : public Personaje{
    private:
        int mana;
        list< Item * > inventario;
    public:
        Jugador();
        void moverJugador(BITMAP *, BITMAP *, int  , int , int  );
        void teclas(BITMAP *, BITMAP *, int * , int *, int, int, int, int );
        int getMana();
        void setMana( int mana );
        void agregarItem( int );
        list<Item *> getInventario();
        void setInventario( list<Item *> inventario );
};

#endif // JUGADOR_H
