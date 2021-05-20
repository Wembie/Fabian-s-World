#include "jugador.h"
const int Jugador :: MAX_ITEMS = 10;

Jugador :: Jugador(){
    this->nombre = "ItsFabian195";
    this->vida = 200;
    this->ataque = 10;
    this->resistencia = 0;
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
	if ( key[KEY_UP] && *y > 50 )
          {
          	moverJugador(prota, buffer, *x, *y, direccionArriba);
          		if(prohibidoArriba != 1){
				  
               		*y-= 3;
               }
          }
          if ( key[KEY_DOWN] && *y < 510  )
          {
          	moverJugador(prota, buffer, *x, *y, direccionAbajo);
               if(prohibidoAbajo != 1){
				  
               		*y+= 3;
               }
          }
          if ( key[KEY_LEFT] && *x > 50 )
          {
          	moverJugador(prota, buffer, *x, *y, direccionIzquierda);
          	if(prohibidoIzquierda != 1){
          		*x -= 3;
			  }
          }
          if ( key[KEY_RIGHT]  && *x < 720  )
          {
          	moverJugador(prota, buffer, *x, *y, direccionDerecha);
          	if( prohibidoDerecha != 1){
			  
               *x+= 3;
			}
          }  
}
