#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <list>
#include <allegro.h>

using std::cin;
using std::cout;
using std::endl; 
using std::string;
//           0      1     2          3             4                 5              6           7
enum Tipo{ESPADA, ARCO, LANZA, POCION_VIDA,POCION_RESISTENCIA, POCION_ATAQUE, POCION_MANA, POCION_DANIO };;

class Item{
    private:
        Tipo tipo;
        BITMAP * texturaItem;
    public:
        Item( Tipo, BITMAP * );
        void mostrarItem( int x, int y, BITMAP * buffer );
};

#endif // ITEM_H
