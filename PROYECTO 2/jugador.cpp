#include "jugador.h"

//Se inicializa el personaje predeterminado con sus respectivos atributos
Jugador :: Jugador() : Personaje( "ItsFabian195", 200, 5, 0 ){
    this->mana = 100;
    //Inventario Iniciado VACIO
}
//Esta funcion mueve la imagen del personaje segun la direccion hacia donde vaya
void Jugador::moverJugador( BITMAP * prota, BITMAP * buffer, int x, int y, int direccion){
	masked_blit(prota, buffer, 0, direccion, x, y, 32,40); //crea blit
}
//Funcion donde el jugador se puede mover, dependiendo de la direccion que vaya es una tecla asignada, tambien se le coloca la posicion (vista del jugador) en la que se encuentra
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
//Retorna el mana del jugador
int Jugador::getMana(){
	return this->mana;
}
//Establece el mana del jugador 
void Jugador::setMana( int mana ){
	this->mana = mana;
}
//Como mencionamos en controller lo de dar item aleatorio este recibe un int el cual lo transformamos en un tipo de tipo TIPO para saber si es una arma o pocion y con ello agregarle
//los atributos acada uno con su textura
void Jugador::agregarItem( int numeroAleatorio ){
	Tipo tipo = static_cast<Tipo>( numeroAleatorio );
	if( tipo == ESPADA || tipo == ARCO || tipo == LANZA ){
		switch(tipo){
			case ESPADA:{
				BITMAP * textura  = load_bmp("espada.bmp",NULL);
				Arma * arma = new Arma( tipo, textura , 25, 3  );
				inventario.push_back( arma );
				break;
				}
			case ARCO:{
				BITMAP * textura  = load_bmp("arco.bmp",NULL);
				Arma * arma = new Arma( tipo, textura, 7, 15  );
				inventario.push_back( arma );
				break;
			}
			case LANZA:{
				BITMAP * textura  = load_bmp("lanza.bmp",NULL);
				Arma * arma = new Arma( tipo, textura, 9, 13  );
				inventario.push_back( arma );
				break;
			}		
		}	
	}
	else if(  tipo == POCION_VIDA || tipo == POCION_RESISTENCIA || tipo == POCION_ATAQUE || tipo == POCION_MANA || tipo ==  POCION_DANIO   ){
		switch(tipo){
			case POCION_VIDA:{
				BITMAP * textura  = load_bmp("pocionVida.bmp",NULL);
				Pocion * pocion = new Pocion( tipo, textura, 40  );
				inventario.push_back( pocion );
				break;
			}
			case POCION_RESISTENCIA:{
				BITMAP * textura  = load_bmp("pocionResistencia.bmp",NULL);
				Pocion * pocion = new Pocion( tipo, textura, 1 );
				inventario.push_back( pocion );
				break;
			}
			case POCION_ATAQUE:{
				BITMAP * textura  = load_bmp("pocionAtaque.bmp",NULL);
				Pocion * pocion = new Pocion( tipo, textura, 2 );
				inventario.push_back( pocion );
				break;
			}
			case POCION_MANA:{
				BITMAP * textura  = load_bmp("pocionMana.bmp",NULL);
				Pocion * pocion = new Pocion( tipo, textura, 50  );
				inventario.push_back( pocion );
				break;
			}
			case POCION_DANIO:{
				BITMAP * textura  = load_bmp("pocionDanio.bmp",NULL);
				Pocion * pocion = new Pocion( tipo, textura, 15 );
				inventario.push_back( pocion );
				break;
			}
		}
	}	
}
//Retorna el inventario del jugador
list <Item *> Jugador::getInventario(){
	return this->inventario;
}
//Trae la lista de inventario xd
void Jugador::setInventario( list<Item * > inventario ){
	this->inventario = inventario;
}