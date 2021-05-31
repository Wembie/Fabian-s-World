#include "enemigo.h"
//Sobrecarga en los constructores
Enemigo :: Enemigo() : Personaje(){
}

Enemigo :: Enemigo( string nombre, int vida, int ataque, int resistencia ) : Personaje( nombre, vida, ataque, resistencia ){
	this->nombre = nombre;
	this->vida = vida;
	this->ataque = ataque;
	this->resistencia = resistencia;
}
//Funcion la cual pone todos los enemigos mediante la matriz que le demos solo en el mapa ya que en batalla son diferentes
void Enemigo::ponerEnemigo( BITMAP * enemigoBase, BITMAP * buffer, list<int>listaPosicioneEnemigos){
	
	list<int>::iterator it2 = listaPosicioneEnemigos.begin();
	it2++;
	for( list<int>::iterator it = listaPosicioneEnemigos.begin(); it != listaPosicioneEnemigos.end(); it++ , it2 ++ ){
		masked_blit(enemigoBase, buffer, 0, 0, *it2 + 5, *it + 5, 40,40);
	  it++;
	  it2++;
	}	
}