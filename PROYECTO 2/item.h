#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <list>
#include <allegro.h>

using std::cin;
using std::cout;
using std::endl; 
using std::string;


//Se crea la clase Item, con sus respetivos metodos

//           0      1     2          3             4                 5              6           7
enum Tipo{ESPADA, ARCO, LANZA, POCION_VIDA,POCION_RESISTENCIA, POCION_ATAQUE, POCION_MANA, POCION_DANIO };;

class Item{
    private:
        Tipo tipo;
    protected:
        BITMAP * texturaItem; //se hace protected para que todos los hijos puedan acceder facilmente a la textura de cada item
    public:
        Item( Tipo, BITMAP * );
        virtual void mostrarItem( int x, int y, BITMAP * buffer ); //Funcion pura para que halla polimorfismo
        Tipo getTipo();
};

#endif // ITEM_H
