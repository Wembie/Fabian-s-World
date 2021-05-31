#include "pocion.h"
//Constructor de Pocion  su atributo y con los diferentes atributos de la clase padre (Item)
Pocion :: Pocion( Tipo tipo, BITMAP * texturaItem , int cantidadDeAumento ) : Item( tipo, texturaItem ){
    this->cantidadDeAumento = cantidadDeAumento;
}
//Retorna la cantidad de aumento de la pocion
int Pocion :: getCantidadDeAumento(){
	return this->cantidadDeAumento;
}
void Pocion::mostrarItem( int x, int y, BITMAP * buffer ){//Metodo de sobreescritura polimorfica
	masked_blit(texturaItem, buffer, 0, 0, x, y, 28,28);
}