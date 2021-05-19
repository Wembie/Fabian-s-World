#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <list>

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
        list< item * > inventario;
    public:
        Jugador();
}

#endif // JUGADOR_H