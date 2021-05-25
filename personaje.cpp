#include "personaje.h"

Personaje :: Personaje(){
	
}
Personaje::Personaje( string nombre, int vida, int ataque, int resistencia ){
	this->nombre = nombre;
	this->vida = vida;
	this->ataque = ataque;
	this->resistencia = resistencia;
}

void Personaje :: moverBatalla( BITMAP * prota, BITMAP * buffer, int x, int y, int accion ){
	masked_blit(prota, buffer, 0, accion, x, y, 32,40); //crea blit
} 

void Personaje :: comienzoBatallaEpica( BITMAP * prota, BITMAP * buffer, int * x, int * y, int comienzaBatalla ){
	int atacar = 1;
	int huir = 2;
	int mochila = 3;
	if ( key[KEY_W] ){
          	moverBatalla(prota, buffer, *x, *y, atacar);
		}
        if ( key[KEY_Q] ){
          	moverBatalla(prota, buffer, *x, *y, huir);
        } 
		if ( key[KEY_E] ){
          	moverBatalla(prota, buffer, *x, *y, mochila);
        }	  
}

int Personaje::getVida(){
	return this->vida;
}

int Personaje::getAtaque(){
	return this->ataque;
}

int Personaje::getResistencia(){
	return this->resistencia;
}

void Personaje::setVida( int vida ){
	this->vida = vida;
}

void Personaje::setResistencia( int resistencia ){
	this->resistencia = resistencia;
}

void Personaje::setAtaque( int ataque ){
	this->ataque = ataque;
}
