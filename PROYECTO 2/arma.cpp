#include "arma.h"

Arma :: Arma( Tipo tipo, BITMAP * texturaItem , int puntosAtaque, int durabilidad ) : Item( tipo, texturaItem ){
    this->puntosAtaque = puntosAtaque;
    this->durabilidad = durabilidad;
}

void Arma::mostrarItem( int x, int y, BITMAP * buffer ){
	masked_blit(texturaItem, buffer, 0, 0, x, y, 28,28);
}

int Arma::getPuntosAtaque(){
	return this->puntosAtaque;
}

int Arma::getDurabilidad(){
	return this->durabilidad;
} 

void Arma::setDurabilidad( int durabilidad ){
	this->durabilidad = durabilidad;
}
