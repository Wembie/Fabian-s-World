#include "jugador.h"
const int Jugador :: MAX_ITEMS = 10;

Jugador :: Jugador(){
    this->nombre = "ItsFabian195";
    this->vida = 200;
    this->ataque = 10;
    this->resistencia = 0;
    //Inventario Iniciado VACIO
}

void Jugador::moverJugador( BITMAP * prota, BITMAP * buffer, int x, int y, int direccion ){
	masked_blit(prota, buffer, 0, direccion, x, y, 32,40); //crea blit
}

void Jugador::teclas(BITMAP * prota, BITMAP * buffer, int * x, int * y ){
	const int direccionArriba = 85;
	const int direccionAbajo = 130;
	const int direccionIzquierda = 40;
	const int direccionDerecha = 0;
	if ( key[KEY_UP] && *y > 50 )
          {
          	moverJugador(prota, buffer, *x, *y, direccionArriba);
               *y-= 3;
          }
          if ( key[KEY_DOWN] && *y < 510  )
          {
          	moverJugador(prota, buffer, *x, *y, direccionAbajo);
               *y+= 3;
          }
          if ( key[KEY_LEFT] && *x > 50 )
          {
          	moverJugador(prota, buffer, *x, *y, direccionIzquierda);
               *x-= 3;
          }
          if ( key[KEY_RIGHT]  && *x < 720 )
          {
          	moverJugador(prota, buffer, *x, *y, direccionDerecha);
               *x+= 3;   
          }  
}
