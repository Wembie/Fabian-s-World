#ifndef POCION_H
#define POCION_H

#include <iostream>
#include <list>

#include "item.h"

using std::cin;
using std::cout;
using std::endl; 
using std::string;

//Se crea la clase Pocion con herencia a Item, su atributo, su constructor y sus diferentes metodos
class Pocion : public Item{
    private:
    	int cantidadDeAumento;
    public:
        Pocion( Tipo, BITMAP * , int );
		void mostrarItem( int x, int y, BITMAP * buffer );
        int getCantidadDeAumento();
        
};

#endif // POCION_H