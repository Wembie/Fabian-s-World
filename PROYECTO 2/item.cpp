#include "item.h"
//Se crea el constructor con sus diferentes atributos
Item :: Item( Tipo tipo, BITMAP *  texturaItem ){
    this->tipo = tipo;
    this->texturaItem = texturaItem;
}
//Funcion que muestra el Item en pantalla / inventario
void Item::mostrarItem( int x, int y, BITMAP * buffer ){
	masked_blit(texturaItem, buffer, 0, 0, x, y, 28,28);
}
//Funcion que retorna el tipo del item
Tipo Item::getTipo(){
	return this->tipo;
}