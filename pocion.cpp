#include "pocion.h"

Pocion :: Pocion( Tipo tipo, BITMAP * texturaItem , int cantidadDeAumento ) : Item( tipo, texturaItem ){
    this->cantidadDeAumento = cantidadDeAumento;
}
