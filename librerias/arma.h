#ifndef ARMA_H
#define ARMA_H

#include <iostream>
#include <list>

#include "item.h"

using std::cin;
using std::cout;
using std::endl; 
using std::string;

enum Tipo{ ESPADA, ARCO, LANZA };

class Arma : public Item{
    private:
        Tipo tipo;
        float puntosAtaque;
        int durabilidad; //O resistencia
    public:
        Arma( string, string, Tipo, float, int );
}

#endif // ARMA_H