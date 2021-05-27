#include "arma.h"

Arma :: Arma( Tipo tipo, BITMAP * texturaItem , int puntosAtaque, int durabilidad ) : Item( tipo, texturaItem ){
    this->puntosAtaque = puntosAtaque;
    this->durabilidad = durabilidad;
}
