#include "pocion.h"

Pocion :: Pocion( Tipo tipo, BITMAP * texturaItem , int cantidadDeAumento ) : Item( tipo, texturaItem ){
    this->cantidadDeAumento = cantidadDeAumento;
}

int Pocion :: getCantidadDeAumento(){
	return this->cantidadDeAumento;
}
void Pocion::mostrarItem( int x, int y, BITMAP * buffer ){
	masked_blit(texturaItem, buffer, 0, 0, x, y, 28,28);
}

