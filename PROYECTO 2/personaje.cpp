#include "personaje.h"
//Sobrecarga en constructores
Personaje :: Personaje(){
	
}
Personaje::Personaje( string nombre, int vida, int ataque, int resistencia ){
	this->nombre = nombre;
	this->vida = vida;
	this->ataque = ataque;
	this->resistencia = resistencia;
}
//En esta funcion mueve al personaje en x o y mas no la imagen de dicho personaje
void Personaje :: moverBatalla( BITMAP * prota, BITMAP * buffer, int x, int y, int accion ){
	masked_blit(prota, buffer, 0, accion, x, y, 32,40); //crea blit
} 

//Retorna la vida
int Personaje::getVida(){
	return this->vida;
}
//Retorna el ataque
int Personaje::getAtaque(){
	return this->ataque;
}
//Retorna la resistencia
int Personaje::getResistencia(){
	return this->resistencia;
}
//Trae la vida
void Personaje::setVida( int vida ){
	this->vida = vida;
}
//Trae la resistencia
void Personaje::setResistencia( int resistencia ){
	this->resistencia = resistencia;
}
//Trae el ataque
void Personaje::setAtaque( int ataque ){
	this->ataque = ataque;
}