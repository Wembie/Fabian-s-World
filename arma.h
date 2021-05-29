#ifndef ARMA_H
#define ARMA_H

#include <iostream>
#include <list>

#include "item.h"

using std::cin;
using std::cout;
using std::endl; 
using std::string;

class Arma : public Item{
    private:
        int puntosAtaque;
        int durabilidad; //O resistencia
    public:
        Arma( Tipo , BITMAP * , int , int );
        void mostrarItem( int x, int y, BITMAP * buffer );
        int getPuntosAtaque();
        int getDurabilidad();
        void setDurabilidad( int );
};

#endif // ARMA_H
