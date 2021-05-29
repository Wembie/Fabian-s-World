#include "item.h"

Item :: Item( Tipo tipo, BITMAP *  texturaItem ){
    this->tipo = tipo;
    this->texturaItem = texturaItem;
}

void Item::mostrarItem( int x, int y, BITMAP * buffer ){
	masked_blit(texturaItem, buffer, 0, 0, x, y, 28,28);
}

Tipo Item::getTipo(){
	return this->tipo;
}

