#include "jugador.h"
const int Jugador :: MAX_ITEMS = 10;

Jugador :: Jugador() : Personaje( "ItsFabian195", 200, 10, 0 ){
    this->mana = 100;
    //Inventario Iniciado VACIO
}

void Jugador::moverJugador( BITMAP * prota, BITMAP * buffer, int x, int y, int direccion){
	masked_blit(prota, buffer, 0, direccion, x, y, 32,40); //crea blit
}

void Jugador::teclas(BITMAP * prota, BITMAP * buffer, int * x, int * y, int prohibidoDerecha, int prohibidoIzquierda, int prohibidoAbajo, int prohibidoArriba  ){
	const int direccionArriba = 85;
	const int direccionAbajo = 130;
	const int direccionIzquierda = 40;
	const int direccionDerecha = 0;
	int movio = 0;
	int yaMostro = 0;
	if ( key[KEY_LEFT] && *x > 50  ){
        if(yaMostro != 1){
          	moverJugador(prota, buffer, *x, *y, direccionIzquierda);
		}
        if(prohibidoIzquierda != 1){
          	*x -= 3;
		}
		movio = 1;
		yaMostro = 1;
        }
        if ( key[KEY_RIGHT]  && *x < 720  ){
          	if(yaMostro != 1){
          		moverJugador(prota, buffer, *x, *y, direccionDerecha);
			}
          	if( prohibidoDerecha != 1){
               *x+= 3;
			}
		movio = 1;
		yaMostro = 1;
        } 
        if(movio == 0){
          	if(yaMostro != 1){
          		moverJugador(prota, buffer, *x, *y, 130);
			}	
		}
		if ( key[KEY_UP] && *y > 50 ){
          	{
          	if(yaMostro != 1){
          		moverJugador(prota, buffer, *x, *y, direccionArriba);
			}
			}
          	if(prohibidoArriba != 1){
               	*y-= 3;
            }
        movio = 1;
        yaMostro = 1;
        }
        if ( key[KEY_DOWN] && *y < 510  ){
          	if(yaMostro != 1){
          		moverJugador(prota, buffer, *x, *y, direccionAbajo);
			}
            if(prohibidoAbajo != 1){
               	*y+= 3;
            }
        movio = 1;
        yaMostro = 1;
    	}	  
}

int Jugador::getMana(){
	return this->mana;
}

void Jugador::setMana( int mana ){
	this->mana = mana;
}
