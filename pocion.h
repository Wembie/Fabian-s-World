#ifndef POCION_H
#define POCION_H

#include <iostream>
#include <list>

#include "item.h"

using std::cin;
using std::cout;
using std::endl; 
using std::string;


class Pocion : public Item{
    private:
    	int cantidadDeAumento;
    public:
        Pocion( Tipo, BITMAP * , int );
};

#endif // POCION_H
