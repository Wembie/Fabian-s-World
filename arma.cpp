#include "arma.h"

Arma :: Arma( string nombre, string descripcion, Tipo tipo, float puntosAtaque, int durabilidad ) : Item( nombre, descripcion ){
    this->puntosAtaque = puntosAtaque;
    this->durabilidad = durabilidad;
    this->tipo = tipo;
}
