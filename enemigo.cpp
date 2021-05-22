#include "enemigo.h"

Enemigo :: Enemigo(){
    this->vida = 100;
    this->ataque = 10;
    this->resistencia = 0;
}

void Enemigo::ponerEnemigo( BITMAP * enemigoBase, BITMAP * buffer, list<int>listaPosicioneEnemigos){
	
	list<int>::iterator it2 = listaPosicioneEnemigos.begin();
	it2++;
	for( list<int>::iterator it = listaPosicioneEnemigos.begin(); it != listaPosicioneEnemigos.end(); it++ , it2 ++ ){
		masked_blit(enemigoBase, buffer, 0, 0, *it2 + 5, *it + 5, 40,40);
      
	  it++;
	  it2++;
	}
	
}




